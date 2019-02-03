/*
 * =====================================================================================
 *
 *       Filename:  Map.cpp
 *
 *    Description:
 *
 *        Created:  14/03/2014 22:40:42
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Debug.hpp"
#include "GameWindow.hpp"
#include "Map.hpp"
#include "MapManager.hpp"
#include "SDLHeaders.hpp"
#include "XMLFile.hpp"

s32 Map::scrollX = 0;
s32 Map::scrollY = 0;

Map::Map(const char *filename, u16 x, u16 y, u16 area, u8 layers, u16 tilesetID) {
	XMLFile doc(filename);

	m_width = doc.FirstChildElement("map").ToElement()->IntAttribute("width");
	m_height = doc.FirstChildElement("map").ToElement()->IntAttribute("height");

	m_layers = layers;
	m_x = x;
	m_y = y;
	m_area = area;

	m_tileset = MapManager::tilesets[tilesetID];

	m_data = new s16*[m_layers];

	tinyxml2::XMLElement *layerElement = doc.FirstChildElement("map").FirstChildElement("layer").ToElement();

	for(u8 i = 0 ; i < m_layers ; i++) {
		m_data[i] = new s16[m_width * m_height];

		tinyxml2::XMLElement *tileElement = layerElement->FirstChildElement("data")->FirstChildElement("tile");

		for(u16 j = 0 ; j < m_width * m_height ; j++) {
			if(!tileElement) break;

			int tile = tileElement->IntAttribute("gid");

			if(tile == -1) m_data[i][j] = 0;
			else m_data[i][j] = tile;

			tileElement = tileElement->NextSiblingElement("tile");
		}

		layerElement = layerElement->NextSiblingElement("layer");
	}

	m_sublayersTex = NULL;
	m_overlayTex = NULL;

	m_battleback = NULL;
}

Map::~Map() {
	if(m_battleback) delete m_battleback;

	for(u8 i = 0 ; i < m_layers ; i++) {
		delete[] m_data[i];
	}

	if(m_overlayTex) SDL_DestroyTexture(m_overlayTex);
	if(m_sublayersTex) SDL_DestroyTexture(m_sublayersTex);

	delete[] m_data;
}

void Map::addEvent(Event *event) {
	m_events.push_back(event);
}

Event *Map::getEvent(std::string name) {
	for(u16 i = 0 ; i < m_events.size() ; i++) {
		if(m_events[i]->name() == name) {
			return m_events[i];
		}
	}
	return NULL;
}

void Map::eventsUpdate() {
	for(u16 i = 0 ; i < m_events.size() ; i++) {
		m_events[i]->update();
	}
}

void Map::updateEventsActions() {
	for(u16 i = 0 ; i < m_events.size() ; i++) {
		m_events[i]->updateActions();
	}
}

void Map::loadTile(u16 tileX, u16 tileY, u8 layer) {
	u16 posX = tileX * m_tileset->tileWidth;
	u16 posY = tileY * m_tileset->tileHeight;

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
	if(m_sublayersTex && m_overlayTex) return;

	SDL_QueryTexture(m_tileset->tiles->texture(), &m_pixelFormat, NULL, NULL, NULL);

	m_sublayersTex = SDL_CreateTexture(GameWindow::main->renderer(), m_pixelFormat, SDL_TEXTUREACCESS_TARGET, m_width * m_tileset->tileWidth, m_height * m_tileset->tileHeight);
	m_overlayTex = SDL_CreateTexture(GameWindow::main->renderer(), m_pixelFormat, SDL_TEXTUREACCESS_TARGET, m_width * m_tileset->tileWidth, m_height * m_tileset->tileHeight);

	SDL_SetTextureBlendMode(m_sublayersTex, SDL_BLENDMODE_BLEND);
	SDL_SetTextureBlendMode(m_overlayTex, SDL_BLENDMODE_BLEND);

	SDL_SetRenderTarget(GameWindow::main->renderer(), m_sublayersTex);

	for(u8 i = 0 ; i < m_layers ; i++) {
		if(i == m_layers - 1) {
			SDL_SetRenderTarget(GameWindow::main->renderer(), m_overlayTex);
		}
		for(u16 y = 0 ; y < m_height ; y++) {
			for(u16 x = 0 ; x < m_width ; x++) {
				loadTile(x, y, i);
			}
		}
	}

	SDL_SetRenderTarget(GameWindow::main->renderer(), NULL);

	for(u16 i = 0 ; i < m_events.size() ; i++) {
		m_events[i]->init();
	}
}

void Map::render() {
	SDL_Rect clip, pos;
	clip.x = scrollX;
	clip.y = scrollY;
	clip.w = GameWindow::main->width();
	clip.h = GameWindow::main->height();
	pos.x =	0;
	pos.y = 0;
	pos.w = GameWindow::main->width();
	pos.h = GameWindow::main->height();
	SDL_RenderCopy(GameWindow::main->renderer(), m_sublayersTex, &clip, &pos);
}

void Map::renderOverlay() {
	SDL_Rect clip, pos;
	clip.x = scrollX;
	clip.y = scrollY;
	clip.w = GameWindow::main->width();
	clip.h = GameWindow::main->height();
	pos.x = 0;
	pos.y = 0;
	pos.w = GameWindow::main->width();
	pos.h = GameWindow::main->height();
	SDL_RenderCopy(GameWindow::main->renderer(), m_overlayTex, &clip, &pos);
}

s16 Map::getTile(u16 tileX, u16 tileY, u16 layer) {
	if(tileX + tileY * m_width < m_width * m_height) {
		return m_data[layer][tileX + tileY * m_width];
	} else {
		warning("Tile out of range: (%d;%d) at layer %d", tileX, tileY, layer);
		return -1; // The tile is out of range
	}
}

void Map::centerMapWithObject(s16 x, s16 y, u16 w, u16 h) {
	scrollX = x - GameWindow::main->width() / 2 + w / 2;
	scrollY = y - GameWindow::main->height() / 2 + h / 2;

	if(scrollX < 0) scrollX = 0;
	if(scrollY < 0) scrollY = 0;
	if(scrollX + GameWindow::main->width() > MapManager::currentMap->width() * MapManager::currentMap->tileset()->tileWidth) scrollX = MapManager::currentMap->width() * MapManager::currentMap->tileset()->tileWidth - GameWindow::main->width() - 1;
	if(scrollY + GameWindow::main->height() > MapManager::currentMap->height() * MapManager::currentMap->tileset()->tileHeight) scrollY = MapManager::currentMap->height() * MapManager::currentMap->tileset()->tileHeight - GameWindow::main->height() - 1;
}

