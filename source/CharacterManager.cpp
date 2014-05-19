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
	
	player = new Player(std::string("") + "graphics/characters/" + className + ((id < 10)?("0"):("")) + to_string(id) + ".png",
						positionElement->IntAttribute("x") * 32,
						positionElement->IntAttribute("y") * 32,
						positionElement->IntAttribute("direction"),
						mapElement->IntAttribute("area"),
						mapElement->IntAttribute("x"),
						mapElement->IntAttribute("y"));
}

void CharacterManager::free() {
	delete player;
}

