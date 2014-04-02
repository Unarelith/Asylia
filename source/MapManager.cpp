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
u16 MapManager::nbTilesets = 0;
u16 MapManager::nbAreas = 0;
u16 *MapManager::areaSizes = NULL;
Map *MapManager::currentMap = NULL;

void MapManager::init() {
	initTilesets();
	initMaps();
}

void MapManager::free() {
	for(u16 i = 0 ; i < nbAreas ; i++) {
		delete[] maps[i];
	}
	delete[] maps;
	
	for(u16 i = 0 ; i < nbTilesets ; i++) {
		delete[] tilesets[i]->nonPassableLayer;
	}
	delete[] tilesets;
}

void MapManager::initTilesets() {
	XMLDocument xml;
	if(xml.LoadFile("data/config/tilesets.xml") != 0) {
		error("Failed to load tilesets data.");
		exit(EXIT_FAILURE);
	}
	
	XMLHandle doc(&xml);
	
	nbTilesets = doc.FirstChildElement("tilesets").ToElement()->IntAttribute("nb");
	
	tilesets = new Tileset*[nbTilesets];
	
	XMLElement *tilesetElement = doc.FirstChildElement("tilesets").FirstChildElement("tileset").ToElement();
	for(unsigned int i = 0 ; i < nbTilesets ; i++) {
		std::stringstream tilesetFilename;
		std::stringstream tilesetInfoFilename;
		
		tilesetFilename << "graphics/tilesets/" << tilesetElement->Attribute("name") << ".png";
		tilesetInfoFilename << "data/tilesets/" << tilesetElement->Attribute("name") << ".tmx";
		
		tilesets[i] = new Tileset;
		tilesets[i]->tiles = new Image(tilesetFilename.str().c_str());
		getNonPassableTiles(tilesetInfoFilename.str().c_str(), tilesets[i]);
		
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
	
	nbAreas = doc.FirstChildElement("maps").ToElement()->IntAttribute("areas");
	
	maps = new Map**[nbAreas];
	areaSizes = new u16[nbAreas];
	
	XMLElement *areaElement = doc.FirstChildElement("maps").FirstChildElement("area").ToElement();
	for(unsigned int i = 0 ; i < nbAreas ; i++) {
		areaSizes[i] = areaElement->IntAttribute("maps");
		maps[i] = new Map*[areaSizes[i]];
		
		XMLElement *mapElement = areaElement->FirstChildElement("map");
		for(unsigned int j = 0 ; j < areaSizes[i] ; j++) {
			std::stringstream mapFilename;
			u8 layers, events;
			u16 x, y, tilesetID;
			
			layers = mapElement->IntAttribute("layers");
			x = mapElement->IntAttribute("x");
			y = mapElement->IntAttribute("y");
			tilesetID = mapElement->IntAttribute("tilesetID");
			events = mapElement->IntAttribute("events");
			
			mapFilename << "data/maps/map" << i << "-" << x << "-" << y << ".tmx";
			
			maps[i][MAP_POS(i, x, y)] = new Map(mapFilename.str().c_str(), x, y, i, layers, tilesetID);
			
			XMLElement *eventElement = mapElement->FirstChildElement("event");
			for(unsigned int k = 0 ; k < events ; k++) {
				std::stringstream eventFolder, eventAppearance;
				std::string eventName, appearance;
				u16 ex, ey;
				u8 anim;
				bool solid;
				
				eventName = eventElement->Attribute("name");
				appearance = eventElement->Attribute("appearance");
				ex = eventElement->IntAttribute("x");
				ey = eventElement->IntAttribute("y");
				anim = eventElement->IntAttribute("anim");
				solid = eventElement->BoolAttribute("solid");
				
				eventFolder << "data/events/" << eventName << "/";
				
				if(appearance != "") {
					eventAppearance << "graphics/characters/" << appearance << ".png";
				}
				
				maps[i][MAP_POS(i, x, y)]->addEvent(new Event(eventFolder.str(), eventName, eventAppearance.str(), ex * 32, ey * 32, anim, i, x, y, solid));
				
				XMLElement *framesizeElement = eventElement->FirstChildElement("framesize");
				if(framesizeElement) {
					maps[i][MAP_POS(i, x, y)]->events().back()->setFrameSize(
						framesizeElement->IntAttribute("width"),
						framesizeElement->IntAttribute("height")
					);
				}
				
				XMLElement *hitboxElement = eventElement->FirstChildElement("hitbox");
				if(hitboxElement) {
					maps[i][MAP_POS(i, x, y)]->events().back()->setHitbox(
						hitboxElement->IntAttribute("x"),
						hitboxElement->IntAttribute("y"),
						hitboxElement->IntAttribute("width"),
						hitboxElement->IntAttribute("height")
					);
				}
				
				eventElement = eventElement->NextSiblingElement("event");
			}
			
			mapElement = mapElement->NextSiblingElement("map");
		}
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

