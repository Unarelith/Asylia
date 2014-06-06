/*
 * =====================================================================================
 *
 *       Filename:  BattleManager.cpp
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

std::vector<Battle*> BattleManager::battles;

void BattleManager::init() {
	XMLFile doc("data/config/battles.xml");
	
	XMLElement *battleElement = doc.FirstChildElement("battles").FirstChildElement("battle").ToElement();
	while(battleElement) {
		Battle *currentBattle;
		std::string battleback;
		
		battleback = std::string("graphics/battlebacks/") + battleElement->Attribute("battleback") + ".jpg";
		
		currentBattle = new Battle(battleback,
								   battleElement->FirstChildElement("result")->IntAttribute("exp"),
								   battleElement->FirstChildElement("result")->IntAttribute("gold"));
		
		XMLElement *actorElement = battleElement->FirstChildElement("actor");
		while(actorElement) {
			currentBattle->addActor(BattlerManager::actors[actorElement->IntAttribute("id")]);
			
			actorElement = actorElement->NextSiblingElement("actor");
		}
		
		XMLElement *enemyElement = battleElement->FirstChildElement("enemy");
		while(enemyElement) {
			s16 x, y;
			
			x = enemyElement->IntAttribute("x");
			y = enemyElement->IntAttribute("y");
			
			currentBattle->addEnemy(BattlerManager::enemies[enemyElement->IntAttribute("id")], x, y);
			
			enemyElement = enemyElement->NextSiblingElement("enemy");
		}
		
		XMLElement *itemElement = battleElement->FirstChildElement("result")->FirstChildElement("item");
		while(itemElement) {
			
		}
		
		battles.push_back(currentBattle);
		
		battleElement = battleElement->NextSiblingElement("battle");
	}
}

void BattleManager::free() {
	while(battles.size() != 0) {
		delete battles.back();
		battles.pop_back();
	}
}

