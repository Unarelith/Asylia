/*
 * =====================================================================================
 *
 *       Filename:  ActorLoader.cpp
 *
 *    Description:
 *
 *        Created:  17/02/2019 21:00:43
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/IntTypes.hpp>
#include <gk/resource/ResourceHandler.hpp>

#include "Actor.hpp"
#include "ActorLoader.hpp"

void ActorLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	int actorCount = 0;
	tinyxml2::XMLElement *actorElement = doc.FirstChildElement("actors").FirstChildElement("actor").ToElement();
	while(actorElement) {
		std::string name, appearance;
		u8 level;

		name = actorElement->Attribute("name");
		appearance = std::string("graphics/battlers/") + actorElement->Attribute("appearance") + ".png";

		level = actorElement->IntAttribute("level");

		Actor &actor = handler.add<Actor>("actor-" + std::to_string(actorCount),
				name, appearance, level);

		actor.calculateAllStats(
			actorElement->FirstChildElement("stats")->IntAttribute("agi"),
			actorElement->FirstChildElement("stats")->IntAttribute("vit"),
			actorElement->FirstChildElement("stats")->IntAttribute("dex"),
			actorElement->FirstChildElement("stats")->IntAttribute("str"),
			actorElement->FirstChildElement("stats")->IntAttribute("wis"),
			actorElement->FirstChildElement("stats")->IntAttribute("int")
		);

		actorCount++;

		actorElement = actorElement->NextSiblingElement("actor");
	}
}

