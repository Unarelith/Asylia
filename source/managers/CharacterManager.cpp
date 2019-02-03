/*
 * =====================================================================================
 *
 *       Filename:  CharacterManager.cpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 20:22:02
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Debug.hpp"
#include "CharacterManager.hpp"
#include "XMLFile.hpp"

Player *CharacterManager::player = nullptr;

void CharacterManager::init() {
	XMLFile doc("data/config/player.xml");

	const char *appearance = doc.FirstChildElement("player").ToElement()->Attribute("appearance");
	tinyxml2::XMLElement *positionElement = doc.FirstChildElement("player").FirstChildElement("position").ToElement();

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

	tinyxml2::XMLElement *actorElement = doc.FirstChildElement("player").FirstChildElement("team").FirstChildElement("actor").ToElement();
	while(actorElement) {
		if(player->teamSize() == 4) {
			warning("Player can't handle more than 4 actors in team.");
			break;
		}

		player->addTeamMember(actorElement->IntAttribute("id"));

		actorElement = actorElement->NextSiblingElement("actor");
	}

	player->getTeamMember(0)->equipment()->equipArmor(player->inventory()->getArmor(0));
}

