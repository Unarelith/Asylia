/*
 * =====================================================================================
 *
 *       Filename:  PlayerLoader.cpp
 *
 *    Description:
 *
 *        Created:  17/02/2019 23:27:13
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/resource/ResourceHandler.hpp>

#include "Player.hpp"
#include "PlayerLoader.hpp"

void PlayerLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	const char *appearance = doc.FirstChildElement("player").ToElement()->Attribute("appearance");
	tinyxml2::XMLElement *positionElement = doc.FirstChildElement("player").FirstChildElement("position").ToElement();

	Player &player = handler.add<Player>("player",
			std::string("texture-character-") + appearance,
			positionElement->IntAttribute("x") * 32,
			positionElement->IntAttribute("y") * 32,
			positionElement->IntAttribute("direction"));

	tinyxml2::XMLElement *actorElement = doc.FirstChildElement("player").FirstChildElement("team").FirstChildElement("actor").ToElement();
	while(actorElement) {
		if(player.teamSize() == 4) {
			DEBUG("Warning: Player can't handle more than 4 actors in team.");
			break;
		}

		player.addTeamMember(actorElement->IntAttribute("id"));

		actorElement = actorElement->NextSiblingElement("actor");
	}

	player.getTeamMember(0)->equipment()->equipArmor(player.inventory()->getArmor(0));
}

