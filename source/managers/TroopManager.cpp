/*
 * =====================================================================================
 *
 *       Filename:  TroopManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27/04/2014 21:10:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
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
		std::string troopback;
		
		troopback = std::string("graphics/troopbacks/") + troopElement->Attribute("troopback") + ".jpg";
		
		currentTroop = new Troop(troopback);
		
		XMLElement *enemyElement = troopElement->FirstChildElement("enemy");
		while(enemyElement) {
			s16 x, y;
			
			x = enemyElement->IntAttribute("x");
			y = enemyElement->IntAttribute("y");
			
			currentTroop->addEnemy(TrooprManager::enemies[enemyElement->IntAttribute("id")], x, y);
			
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

