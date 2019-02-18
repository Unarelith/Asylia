/*
 * =====================================================================================
 *
 *       Filename:  MapManager.cpp
 *
 *    Description:
 *
 *        Created:  21/03/2014 19:15:45
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <sstream>

#include <gk/core/XMLFile.hpp>

#include "MapManager.hpp"
#include "ResourceHelper.hpp"

template<>
MapManager *Singleton<MapManager>::s_instance = nullptr;

void MapManager::init() {
	gk::XMLFile doc("data/config/maps.xml");

	tinyxml2::XMLElement *areasElement = doc.FirstChildElement("maps").ToElement();
	tinyxml2::XMLElement *areaElement = areasElement->FirstChildElement("area");
	u16 areaID = 0;
	while(areaElement) {
		tinyxml2::XMLElement *mapElement = areaElement->FirstChildElement("map");
		std::vector<std::unique_ptr<Map>> currentArea;
		while(mapElement) {
			std::stringstream mapFilename;
			u8 layers;
			u16 x, y, tilesetID;

			layers = mapElement->IntAttribute("layers");
			x = mapElement->IntAttribute("x");
			y = mapElement->IntAttribute("y");
			tilesetID = mapElement->IntAttribute("tilesetID");

			mapFilename << "data/maps/map" << areaID << "-" << x << "-" << y << ".tmx";

			currentArea.emplace_back(new Map(mapFilename.str().c_str(), x, y, areaID, layers, tilesetID));

			currentArea.back()->setBattleback(new Image(std::string(std::string("graphics/battlebacks/") + mapElement->Attribute("battleback") + ".jpg").c_str()));

			tinyxml2::XMLElement *eventElement = mapElement->FirstChildElement("event");
			while(eventElement) {
				currentArea.back()->addEvent(ResourceHelper::getEvent(eventElement->Attribute("name")));

				eventElement = eventElement->NextSiblingElement("event");
			}

			mapElement = mapElement->NextSiblingElement("map");
		}

		m_maps.emplace_back(std::move(currentArea));

		areaID++;

		areaElement = areaElement->NextSiblingElement("area");
	}

	u16 startarea = areasElement->IntAttribute("startarea");
	u16 startx = areasElement->IntAttribute("startx");
	u16 starty = areasElement->IntAttribute("starty");

	m_currentMap = m_maps[startarea][MAP_POS(startarea, startx, starty)].get();
}

bool passable(s16 x, s16 y) {
	for(u16 i = 0 ; i < MapManager::getInstance().getCurrentMap()->layers() ; i++) {
		int tile = MapManager::getInstance().getCurrentMap()->getTile(x / MapManager::getInstance().getCurrentMap()->tileset()->tileWidth, y / MapManager::getInstance().getCurrentMap()->tileset()->tileHeight, i) - 1;
		if(tile < 0 || MapManager::getInstance().getCurrentMap()->tileset()->nonPassableLayer[tile] == 0)
			continue;
		else return false;
	}

	return true;
}

