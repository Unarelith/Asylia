/*
 * =====================================================================================
 *
 *       Filename:  BattlerManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27/04/2014 20:45:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

std::vector<Actor*> BattlerManager::actors;
std::vector<Enemy*> BattlerManager::enemies;

void BattlerManager::init() {
	initActors();
	initEnemies();
}

void BattlerManager::initActors() {
	XMLFile doc("data/config/actors.xml");
	
	XMLElement *actorElement = doc.FirstChildElement("actors").FirstChildElement("actor").ToElement();
	while(actorElement) {
		std::string name, appearance;
		u8 level;
		
		name = actorElement->Attribute("name");
		appearance = std::string("graphics/battlers/") + actorElement->Attribute("appearance") + ".png";
		
		level = actorElement->IntAttribute("level");
		
		actors.push_back(new Actor(name, appearance, level));
		
		actors.back()->calculateAllStats(
			actorElement->FirstChildElement("stats")->IntAttribute("agi"),
			actorElement->FirstChildElement("stats")->IntAttribute("vit"),
			actorElement->FirstChildElement("stats")->IntAttribute("dex"),
			actorElement->FirstChildElement("stats")->IntAttribute("str"),
			actorElement->FirstChildElement("stats")->IntAttribute("wis"),
			actorElement->FirstChildElement("stats")->IntAttribute("int")
		);
		
		actorElement = actorElement->NextSiblingElement("actor");
	}
}

void BattlerManager::initEnemies() {
	XMLFile doc("data/config/enemies.xml");
	
	XMLElement *enemyElement = doc.FirstChildElement("enemies").FirstChildElement("enemy").ToElement();
	while(enemyElement) {
		std::string name, appearance;
		u8 level;
		
		name = enemyElement->Attribute("name");
		appearance = std::string("graphics/battlers/") + enemyElement->Attribute("appearance") + ".png";
		
		level = enemyElement->IntAttribute("level");
		
		enemies.push_back(new Enemy(name, appearance, level));
		
		enemies.back()->calculateAllStats(
			enemyElement->FirstChildElement("stats")->IntAttribute("agi"),
			enemyElement->FirstChildElement("stats")->IntAttribute("vit"),
			enemyElement->FirstChildElement("stats")->IntAttribute("dex"),
			enemyElement->FirstChildElement("stats")->IntAttribute("str"),
			enemyElement->FirstChildElement("stats")->IntAttribute("wis"),
			enemyElement->FirstChildElement("stats")->IntAttribute("int")
		);
		
		enemyElement = enemyElement->NextSiblingElement("enemy");
	}
}

void BattlerManager::free() {
	while(actors.size() != 0) {
		delete actors.back();
		actors.pop_back();
	}
	
	while(enemies.size() != 0) {
		delete enemies.back();
		enemies.pop_back();
	}
}

