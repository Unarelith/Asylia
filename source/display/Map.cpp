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
#include <gk/core/SDLHeaders.hpp>
#include <gk/core/XMLFile.hpp>

#include "Debug.hpp"
#include "GameWindow.hpp"
#include "Map.hpp"
#include "ResourceHelper.hpp"

s32 Map::scrollX = 0;
s32 Map::scrollY = 0;

Map::Map(const char *filename, u16 x, u16 y, u16 area, u8 layers, u16 tilesetID) {
	gk::XMLFile doc(filename);

	m_width = doc.FirstChildElement("map").ToElement()->IntAttribute("width");
	m_height = doc.FirstChildElement("map").ToElement()->IntAttribute("height");

	m_layers = layers;
	m_x = x;
	m_y = y;
	m_area = area;

	m_tileset = ResourceHelper::getTileset(tilesetID);

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

	m_sublayersTex = nullptr;
	m_overlayTex = nullptr;

	m_battleback = nullptr;
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
	return nullptr;
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

	SDL_QueryTexture(m_tileset->tiles->texture(), &m_pixelFormat, nullptr, nullptr, nullptr);

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

	SDL_SetRenderTarget(GameWindow::main->renderer(), nullptr);

	for(u16 i = 0 ; i < m_events.size() ; i++) {
		m_events[i]->init();
	}
}

void Map::render() {
	SDL_Rect clip, pos;
	clip.x = scrollX;
	clip.y = scrollY;
	clip.w = SCREEN_WIDTH;
	clip.h = SCREEN_HEIGHT;
	pos.x =	0;
	pos.y = 0;
	pos.w = SCREEN_WIDTH;
	pos.h = SCREEN_HEIGHT;
	SDL_RenderCopy(GameWindow::main->renderer(), m_sublayersTex, &clip, &pos);
}

void Map::renderOverlay() {
	SDL_Rect clip, pos;
	clip.x = scrollX;
	clip.y = scrollY;
	clip.w = SCREEN_WIDTH;
	clip.h = SCREEN_HEIGHT;
	pos.x = 0;
	pos.y = 0;
	pos.w = SCREEN_WIDTH;
	pos.h = SCREEN_HEIGHT;
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

bool Map::passable(s16 x, s16 y) {
	for(u16 i = 0 ; i < ResourceHelper::getCurrentMap()->layers() ; i++) {
		int tile = ResourceHelper::getCurrentMap()->getTile(
				x / ResourceHelper::getCurrentMap()->tileset()->tileWidth,
				y / ResourceHelper::getCurrentMap()->tileset()->tileHeight, i) - 1;

		if(tile < 0 || ResourceHelper::getCurrentMap()->tileset()->nonPassableLayer[tile] == 0)
			continue;
		else return false;
	}

	return true;
}

void Map::centerMapWithObject(s16 x, s16 y, u16 w, u16 h) {
	scrollX = x - SCREEN_WIDTH / 2 + w / 2;
	scrollY = y - SCREEN_HEIGHT / 2 + h / 2;

	if(scrollX < 0) scrollX = 0;
	if(scrollY < 0) scrollY = 0;
	if(scrollX + SCREEN_WIDTH > ResourceHelper::getCurrentMap()->width() * ResourceHelper::getCurrentMap()->tileset()->tileWidth)
		scrollX = ResourceHelper::getCurrentMap()->width() * ResourceHelper::getCurrentMap()->tileset()->tileWidth - SCREEN_WIDTH - 1;
	if(scrollY + SCREEN_HEIGHT > ResourceHelper::getCurrentMap()->height() * ResourceHelper::getCurrentMap()->tileset()->tileHeight)
		scrollY = ResourceHelper::getCurrentMap()->height() * ResourceHelper::getCurrentMap()->tileset()->tileHeight - SCREEN_HEIGHT - 1;
}

