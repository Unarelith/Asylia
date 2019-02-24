/*
 * =====================================================================================
 *
 *       Filename:  TroopLoader.cpp
 *
 *    Description:
 *
 *        Created:  17/02/2019 20:58:38
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/resource/ResourceHandler.hpp>

#include "Troop.hpp"
#include "TroopLoader.hpp"

void TroopLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	int troopCount = 0;
	tinyxml2::XMLElement *troopElement = doc.FirstChildElement("troops").FirstChildElement("troop").ToElement();
	while(troopElement) {
		Troop *currentTroop;
		std::string battleback;

		if(!troopElement->Attribute("battleback", "")) {
			battleback = std::string("texture-battleback") + troopElement->Attribute("battleback");
			currentTroop = &handler.add<Troop>("troop-" + std::to_string(troopCount), battleback);
		} else {
			currentTroop = &handler.add<Troop>("troop-" + std::to_string(troopCount));
		}

		tinyxml2::XMLElement *enemyElement = troopElement->FirstChildElement("enemy");
		while(enemyElement) {
			s16 x, y;

			x = enemyElement->IntAttribute("x");
			y = enemyElement->IntAttribute("y");

			Enemy *enemy = &handler.get<Enemy>("enemy-" + std::to_string(enemyElement->IntAttribute("id")));
			currentTroop->addEnemy(enemy, x, y);

			enemyElement = enemyElement->NextSiblingElement("enemy");
		}

		troopCount++;

		troopElement = troopElement->NextSiblingElement("troop");
	}
}

