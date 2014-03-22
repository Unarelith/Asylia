/*
 * =====================================================================================
 *
 *       Filename:  CharacterManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 20:22:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Player *CharacterManager::player = NULL;

void CharacterManager::init() {
	XMLDocument xml;
	if(xml.LoadFile("data/config/player.xml") != 0) {
		error("Failed to load player data");
		exit(EXIT_FAILURE);
	}
	
	XMLHandle doc(&xml);
	
	const char *className = doc.FirstChildElement("player").FirstChildElement("appearance").ToElement()->Attribute("class");
	u16 id = doc.FirstChildElement("player").FirstChildElement("appearance").ToElement()->IntAttribute("id");
	XMLElement *positionElement = doc.FirstChildElement("player").FirstChildElement("position").ToElement();
	XMLElement *mapElement = doc.FirstChildElement("player").FirstChildElement("map").ToElement();
	
	std::stringstream filename;
	
	filename << "graphics/characters/" << className << std::string((id < 10)?("0"):("")) << id << ".png";
	
	player = new Player(filename.str().c_str(),
						positionElement->IntAttribute("x") << 4,
						positionElement->IntAttribute("y") << 4,
						positionElement->IntAttribute("direction") << 4,
						mapElement->IntAttribute("area") << 4,
						mapElement->IntAttribute("x") << 4,
						mapElement->IntAttribute("y") << 4);
}

void CharacterManager::free() {
	delete player;
}

