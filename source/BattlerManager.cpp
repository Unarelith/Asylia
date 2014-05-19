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
	XMLDocument xml;
	int code = xml.LoadFile("data/config/actors.xml");
	if(code != 0) {
		error("Failed to load actors data. (CODE: %d)", code);
		exit(EXIT_FAILURE);
	}
	
	XMLHandle doc(&xml);
	
	XMLElement *actorElement = doc.FirstChildElement("actors").FirstChildElement("actor").ToElement();
	while(actorElement) {
		std::string name, appearance;
		u8 level;
		s16 hp, sp;
		u16 atk, def;
		
		name = actorElement->Attribute("name");
		appearance = std::string("") + "graphics/battlers/" + actorElement->Attribute("appearance") + ".png";
		
		level = actorElement->FirstChildElement("stats")->IntAttribute("level");
		
		hp = actorElement->FirstChildElement("stats")->IntAttribute("hp");
		sp = actorElement->FirstChildElement("stats")->IntAttribute("sp");
		
		atk = actorElement->FirstChildElement("stats")->IntAttribute("atk");
		def = actorElement->FirstChildElement("stats")->IntAttribute("def");
		
		actors.push_back(new Actor(name, appearance, level, hp, sp, atk, def));
		
		XMLElement *charalinkElement = actorElement->FirstChildElement("charalink");
		if(charalinkElement) {
			s16 id = charalinkElement->IntAttribute("id");
			
			if(id == -1) {
				actors.back()->linkInventory(CharacterManager::player->inventory());
				CharacterManager::player->linkBattler((Battler*)actors.back());
			}
		}
		
		actorElement = actorElement->NextSiblingElement("actor");
	}
}

void BattlerManager::initEnemies() {
	XMLDocument xml;
	int code = xml.LoadFile("data/config/enemies.xml");
	if(code != 0) {
		error("Failed to load enemies data. (CODE: %d)", code);
		exit(EXIT_FAILURE);
	}
	
	XMLHandle doc(&xml);
	
	XMLElement *enemyElement = doc.FirstChildElement("enemies").FirstChildElement("enemy").ToElement();
	while(enemyElement) {
		std::string name, appearance;
		u8 level;
		s16 hp, sp;
		u16 atk, def;
		
		name = enemyElement->Attribute("name");
		appearance = std::string("") + "graphics/battlers/" + enemyElement->Attribute("appearance") + ".png";
		
		level = enemyElement->FirstChildElement("stats")->IntAttribute("level");
		
		hp = enemyElement->FirstChildElement("stats")->IntAttribute("hp");
		sp = enemyElement->FirstChildElement("stats")->IntAttribute("sp");
		
		atk = enemyElement->FirstChildElement("stats")->IntAttribute("atk");
		def = enemyElement->FirstChildElement("stats")->IntAttribute("def");
		
		enemies.push_back(new Enemy(name, appearance, level, hp, sp, atk, def));
		
		XMLElement *charalinkElement = enemyElement->FirstChildElement("charalink");
		if(charalinkElement) {
			s16 id = charalinkElement->IntAttribute("id");
			
			if(id == -1) {
				actors.back()->linkInventory(CharacterManager::player->inventory());
				CharacterManager::player->linkBattler((Battler*)actors.back());
			}
		}
		
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

