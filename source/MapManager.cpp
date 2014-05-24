/*
 * =====================================================================================
 *
 *       Filename:  MapManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/03/2014 19:15:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Tileset **MapManager::tilesets = NULL;
Map ***MapManager::maps = NULL;
Map *MapManager::currentMap = NULL;

void MapManager::init() {
	initTilesets();
	initMaps();
}

void MapManager::free() {
	while(maps.size() != 0) {
		while(maps.back().size() != 0) {
			delete maps.back().back();
			maps.back().pop_back();
		}
		maps.pop_back();
	}
	
	while(tilesets.size() != 0) {
		delete tilesets.back();
		tilesets.pop_back();
	}
}

void MapManager::initTilesets() {
	XMLDocument xml;
	if(xml.LoadFile("data/config/tilesets.xml") != 0) {
		error("Failed to load tilesets data.");
		exit(EXIT_FAILURE);
	}
	
	XMLHandle doc(&xml);
	
	XMLElement *tilesetElement = doc.FirstChildElement("tilesets").FirstChildElement("tileset").ToElement();
	while(tilesetElement) {
		std::stringstream tilesetFilename;
		std::stringstream tilesetInfoFilename;
		
		tilesetFilename << "graphics/tilesets/" << tilesetElement->Attribute("name") << ".png";
		tilesetInfoFilename << "data/tilesets/" << tilesetElement->Attribute("name") << ".tmx";
		
		tilesets.push_back(new Tileset)
		tilesets.back()->tiles = new Image(tilesetFilename.str().c_str());
		getNonPassableTiles(tilesetInfoFilename.str().c_str(), tilesets.back());
		
		tilesetElement = tilesetElement->NextSiblingElement("tileset");
	}
}

void MapManager::initMaps() {
	XMLDocument xml;
	int code = xml.LoadFile("data/config/maps.xml");
	if(code != 0) {
		error("Failed to load maps data. (CODE: %d)", code);
		exit(EXIT_FAILURE);
	}
	
	XMLHandle doc(&xml);
	
	maps.push_back()
	
	XMLElement *areaElement = doc.FirstChildElement("maps").FirstChildElement("area").ToElement();
	while(areaElement) {
		XMLElement *mapElement = areaElement->FirstChildElement("map");
		std::vector<Map*> currentArea;
		while(mapElement) {
			std::stringstream mapFilename;
			u8 layers, events;
			u16 x, y, tilesetID;
			
			layers = mapElement->IntAttribute("layers");
			x = mapElement->IntAttribute("x");
			y = mapElement->IntAttribute("y");
			tilesetID = mapElement->IntAttribute("tilesetID");
			
			mapFilename << "data/maps/map" << i << "-" << x << "-" << y << ".tmx";
			
			currentArea.push_back(new Map(mapFilename.str().c_str(), x, y, i, layers, tilesetID));
			
			XMLElement *eventElement = mapElement->FirstChildElement("event");
			while(eventElement) {
				currentArea.back()->addEvent(EventManager::getEventByName(eventElement->Attribute("name")));
				
				eventElement = eventElement->NextSiblingElement("event");
			}
			
			mapElement = mapElement->NextSiblingElement("map");
		}
		
		map.push_back(currentArea);
		
		areaElement = areaElement->NextSiblingElement("area");
	}
}

void getNonPassableTiles(const char *filename, Tileset *tileset) {
	XMLDocument xml;
	if(xml.LoadFile(filename) != 0) {
		error("Failed to load tileset info: %s", filename);
		exit(EXIT_FAILURE);
	}
	
	XMLHandle doc(&xml);
	
	XMLElement *nonPassableTilesElement = doc.FirstChildElement("map").FirstChildElement("layer").NextSiblingElement().ToElement();
	if(!nonPassableTilesElement) return;
	
	u16 size = nonPassableTilesElement->IntAttribute("width") * nonPassableTilesElement->IntAttribute("height");
	
	tileset->nonPassableLayer = new u16[size];
	
	XMLElement *tileElement = nonPassableTilesElement->FirstChildElement("data")->FirstChildElement("tile");
	
	for(u16 i = 0 ; i < size ; i++) {
		if(!tileElement) break;
		
		s16 tile = tileElement->IntAttribute("gid") - 1;
		
		if(tile == -1) tileset->nonPassableLayer[i] = 0;
		else tileset->nonPassableLayer[i] = tile;
		
		tileElement = tileElement->NextSiblingElement("tile");
	}
}

bool passable(s16 x, s16 y) {
	for(u16 i = 0 ; i < MapManager::currentMap->layers() ; i++) {
		if(MapManager::currentMap->tileset()->nonPassableLayer[MapManager::currentMap->getTile(x / MapManager::currentMap->tileset()->tileWidth, y / MapManager::currentMap->tileset()->tileHeight, i) - 1] == 0)
			continue;
		else return false;
	}
	
	return true;
}

