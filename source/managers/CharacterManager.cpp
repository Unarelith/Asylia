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
	XMLFile doc("data/config/player.xml");
	
	const char *className = doc.FirstChildElement("player").FirstChildElement("appearance").ToElement()->Attribute("class");
	u16 id = doc.FirstChildElement("player").FirstChildElement("appearance").ToElement()->IntAttribute("id");
	XMLElement *positionElement = doc.FirstChildElement("player").FirstChildElement("position").ToElement();
	
	player = new Player(std::string("") + "graphics/characters/" + className + ((id < 10)?("0"):("")) + to_string(id) + ".png",
						positionElement->IntAttribute("x") * 32,
						positionElement->IntAttribute("y") * 32,
						positionElement->IntAttribute("direction"));
	
	XMLElement *actorElement = doc.FirstChildElement("player").FirstChildElement("team").FirstChildElement("actor").ToElement();
	while(actorElement) {
		if(player->teamSize() == 4) {
			warning("Player can't handle more than 4 actors in team.");
			break;
		}
		
		player->addTeamMember(actorElement->IntAttribute("id"));
		
		actorElement = actorElement->NextSiblingElement("actor");
	}
}

void CharacterManager::free() {
	delete player;
}

