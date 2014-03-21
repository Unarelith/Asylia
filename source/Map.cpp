/*
 * =====================================================================================
 *
 *       Filename:  Map.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/03/2014 22:40:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Map::Map(const char *filename, u16 x, u16 y, u16 area, u8 layers, u16 tilesetID) {
	XMLDocument xml;
	if(xml.LoadFile(filename) != 0) {
		error("Failed to load map: %s", filename);
		exit(EXIT_FAILURE);
	}
	
	XMLHandle doc(&xml);
	
	m_width = doc.FirstChildElement("map").ToElement()->IntAttribute("width");
	m_height = doc.FirstChildElement("map").ToElement()->IntAttribute("height");
	
	m_layers = layers;
	m_x = x;
	m_y = y;
	m_area = area;
	
	m_tileset = MapManager::tilesets[tilesetID];
	
	m_data = new s16*[m_layers];
	
	XMLElement *layerElement = doc.FirstChildElement("map").FirstChildElement("layer").ToElement();
	
	for(u8 i = 0 ; i < m_layers ; i++) {
		m_data[i] = new s16[m_width * m_height];
		
		XMLElement *tileElement = layerElement->FirstChildElement("data")->FirstChildElement("tile");
		
		for(u16 j = 0 ; j < m_width * m_height ; j++) {
			if(!tileElement) break;
			
			int tile = tileElement->IntAttribute("gid");
			
			if(tile == -1) m_data[i][j] = 0;
			else m_data[i][j] = tile;
			
			tileElement = tileElement->NextSiblingElement("tile");
		}
		
		layerElement = layerElement->NextSiblingElement("layer");
	}
	
	m_layersTex = new SDL_Texture*[m_layers];
	SDL_QueryTexture(m_tileset->tiles->texture(), &m_pixelFormat, NULL, NULL, NULL);
}

Map::~Map() {
	for(u8 i = 0 ; i < m_layers ; i++) {
		SDL_DestroyTexture(m_layersTex[i]);
		delete[] m_data[i];
	}
	
	delete[] m_layersTex;
	delete[] m_data;
}

void Map::loadTile(u16 tileX, u16 tileY, u8 layer) {
	u16 posX = (tileX + m_x * m_width) * m_tileset->tileWidth;
	u16 posY = (tileY + m_y * m_height) * m_tileset->tileHeight;
	
	u16 tileID = getTile(tileX, tileY, layer);
	if(tileID == 0) return;
	tileID--;
	
	u16 tilesetY = (tileID / (m_tileset->tiles->width() / m_tileset->tileHeight)) * m_tileset->tileHeight;
	u16 tilesetX = (tileID - (tilesetY / m_tileset->tileHeight) * (m_tileset->tiles->width() / m_tileset->tileHeight)) * m_tileset->tileWidth;
	
	m_tileset->tiles->render(posX, posY, m_tileset->tileWidth, m_tileset->tileHeight, tilesetX, tilesetY, m_tileset->tileWidth, m_tileset->tileHeight);
	
#ifdef NONPASSABLETILES_DEBUG
	if(m_tileset->nonPassableLayer[tileID] != 0) GameWindow::main->drawFillRect(posX, posY, m_tileset->tileWidth, m_tileset->tileHeight, Color(255, 0, 255));
#endif
}

void Map::load() {
	for(u8 i = 0 ; i < m_layers ; i++) {
		m_layersTex[i] = SDL_CreateTexture(GameWindow::main->renderer(), m_pixelFormat, SDL_TEXTUREACCESS_TARGET, m_width * m_tileset->tileWidth, m_height * m_tileset->tileHeight);
		SDL_SetTextureBlendMode(m_layersTex[i], SDL_BLENDMODE_BLEND);
		SDL_SetRenderTarget(GameWindow::main->renderer(), m_layersTex[i]);
		
		for(u16 y = 0 ; y < m_height ; y++) {
			for(u16 x = 0 ; x < m_width ; x++) {
				loadTile(x, y, i);
			}
		}
	}
	SDL_SetRenderTarget(GameWindow::main->renderer(), NULL);
}

void Map::render() {
	for(u8 i = 0 ; i < m_layers - 1 ; i++) {
		SDL_Rect clip, pos;
		clip.x = GameWindow::main->viewportX();
		clip.y = GameWindow::main->viewportY();
		clip.w = GameWindow::main->width();
		clip.h = GameWindow::main->height();
		pos.x = GameWindow::main->viewportX();
		pos.y = GameWindow::main->viewportY();
		pos.w = GameWindow::main->width();
		pos.h = GameWindow::main->height();
		SDL_RenderCopy(GameWindow::main->renderer(), m_layersTex[i], &clip, &pos);
	}
}

void Map::renderOverlay() {
	SDL_Rect clip, pos;
	clip.x = GameWindow::main->viewportX();
	clip.y = GameWindow::main->viewportY();
	clip.w = GameWindow::main->width();
	clip.h = GameWindow::main->height();
	pos.x = GameWindow::main->viewportX();
	pos.y = GameWindow::main->viewportY();
	pos.w = GameWindow::main->width();
	pos.h = GameWindow::main->height();
	SDL_RenderCopy(GameWindow::main->renderer(), m_layersTex[m_layers - 1], &clip, &pos);
}

s16 Map::getTile(u16 tileX, u16 tileY, u16 layer) {
	if(tileX + tileY * m_width < m_width * m_height) {
		return m_data[layer][tileX + tileY * m_width];
	} else {
		warn("Tile out of range: (%d;%d) at layer %d", tileX, tileY, layer);
		return -1; // The tile is out of range
	}
}

