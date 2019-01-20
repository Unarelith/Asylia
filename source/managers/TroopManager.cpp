/*
 * =====================================================================================
 *
 *       Filename:  TroopManager.cpp
 *
 *    Description:
 *
 *        Created:  27/04/2014 21:10:51
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

std::vector<Troop*> TroopManager::troops;

void TroopManager::init() {
	XMLFile doc("data/config/troops.xml");

	XMLElement *troopElement = doc.FirstChildElement("troops").FirstChildElement("troop").ToElement();
	while(troopElement) {
		Troop *currentTroop;
		std::string battleback;

		if(!troopElement->Attribute("battleback", "")) {
			battleback = std::string("graphics/battlebacks/") + troopElement->Attribute("battleback") + ".jpg";
			currentTroop = new Troop(new Image(battleback.c_str()));
		} else {
			currentTroop = new Troop;
		}

		XMLElement *enemyElement = troopElement->FirstChildElement("enemy");
		while(enemyElement) {
			s16 x, y;

			x = enemyElement->IntAttribute("x");
			y = enemyElement->IntAttribute("y");

			currentTroop->addEnemy(BattlerManager::enemies[enemyElement->IntAttribute("id")], x, y);

			enemyElement = enemyElement->NextSiblingElement("enemy");
		}

		troops.push_back(currentTroop);

		troopElement = troopElement->NextSiblingElement("troop");
	}
}

void TroopManager::free() {
	while(troops.size() != 0) {
		delete troops.back();
		troops.pop_back();
	}
}

