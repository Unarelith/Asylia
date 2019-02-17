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
#include <gk/core/XMLFile.hpp>

#include "Debug.hpp"
#include "CharacterManager.hpp"

template<>
CharacterManager *Singleton<CharacterManager>::s_instance = nullptr;

void CharacterManager::init() {
	gk::XMLFile doc("data/config/player.xml");

	const char *appearance = doc.FirstChildElement("player").ToElement()->Attribute("appearance");
	tinyxml2::XMLElement *positionElement = doc.FirstChildElement("player").FirstChildElement("position").ToElement();

	m_player.reset(new Player(std::string("graphics/characters/") + appearance + ".png",
						positionElement->IntAttribute("x") * 32,
						positionElement->IntAttribute("y") * 32,
						positionElement->IntAttribute("direction")));
}

void CharacterManager::loadActorsTeam() {
	gk::XMLFile doc("data/config/player.xml");

	tinyxml2::XMLElement *actorElement = doc.FirstChildElement("player").FirstChildElement("team").FirstChildElement("actor").ToElement();
	while(actorElement) {
		if(m_player->teamSize() == 4) {
			warning("Player can't handle more than 4 actors in team.");
			break;
		}

		m_player->addTeamMember(actorElement->IntAttribute("id"));

		actorElement = actorElement->NextSiblingElement("actor");
	}

	m_player->getTeamMember(0)->equipment()->equipArmor(m_player->inventory()->getArmor(0));
}

