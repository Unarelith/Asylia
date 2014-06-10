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
	
	const char *appearance = doc.FirstChildElement("player").ToElement()->Attribute("appearance");
	XMLElement *positionElement = doc.FirstChildElement("player").FirstChildElement("position").ToElement();
	
	player = new Player(std::string("graphics/characters/") + appearance + ".png",
						positionElement->IntAttribute("x") * 32,
						positionElement->IntAttribute("y") * 32,
						positionElement->IntAttribute("direction"));
}

void CharacterManager::free() {
	delete player;
}

void CharacterManager::loadActorsTeam() {
	XMLFile doc("data/config/player.xml");
	
	XMLElement *actorElement = doc.FirstChildElement("player").FirstChildElement("team").FirstChildElement("actor").ToElement();
	while(actorElement) {
		if(player->teamSize() == 4) {
			warning("Player can't handle more than 4 actors in team.");
			break;
		}
		
		player->addTeamMember(actorElement->IntAttribute("id"));
		
		actorElement = actorElement->NextSiblingElement("actor");
	}
	
	player->getTeamMember(0)->equipArmor(player->inventory()->getArmor(0));
}

