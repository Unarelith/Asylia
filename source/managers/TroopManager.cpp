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
#include "BattlerManager.hpp"
#include "TroopManager.hpp"
#include "XMLFile.hpp"

template<>
TroopManager *Singleton<TroopManager>::s_instance = nullptr;

void TroopManager::init() {
	XMLFile doc("data/config/troops.xml");

	tinyxml2::XMLElement *troopElement = doc.FirstChildElement("troops").FirstChildElement("troop").ToElement();
	while(troopElement) {
		Troop *currentTroop;
		std::string battleback;

		if(!troopElement->Attribute("battleback", "")) {
			battleback = std::string("graphics/battlebacks/") + troopElement->Attribute("battleback") + ".jpg";
			currentTroop = new Troop(battleback);
		} else {
			currentTroop = new Troop;
		}

		tinyxml2::XMLElement *enemyElement = troopElement->FirstChildElement("enemy");
		while(enemyElement) {
			s16 x, y;

			x = enemyElement->IntAttribute("x");
			y = enemyElement->IntAttribute("y");

			currentTroop->addEnemy(BattlerManager::getInstance().getEnemy(enemyElement->IntAttribute("id")), x, y);

			enemyElement = enemyElement->NextSiblingElement("enemy");
		}

		m_troops.emplace_back(currentTroop);

		troopElement = troopElement->NextSiblingElement("troop");
	}
}

