/*
 * =====================================================================================
 *
 *       Filename:  BattlerManager.cpp
 *
 *    Description:
 *
 *        Created:  27/04/2014 20:45:58
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "BattlerManager.hpp"
#include "XMLFile.hpp"

template<>
BattlerManager *Singleton<BattlerManager>::s_instance = nullptr;

void BattlerManager::init() {
	initActors();
	initEnemies();
}

void BattlerManager::initActors() {
	XMLFile doc("data/config/actors.xml");

	tinyxml2::XMLElement *actorElement = doc.FirstChildElement("actors").FirstChildElement("actor").ToElement();
	while(actorElement) {
		std::string name, appearance;
		u8 level;

		name = actorElement->Attribute("name");
		appearance = std::string("graphics/battlers/") + actorElement->Attribute("appearance") + ".png";

		level = actorElement->IntAttribute("level");

		m_actors.emplace_back(new Actor(name, appearance, level));

		m_actors.back()->calculateAllStats(
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

	tinyxml2::XMLElement *enemyElement = doc.FirstChildElement("enemies").FirstChildElement("enemy").ToElement();
	while(enemyElement) {
		std::string name, appearance;
		u8 level;

		name = enemyElement->Attribute("name");
		appearance = std::string("graphics/battlers/") + enemyElement->Attribute("appearance") + ".png";

		level = enemyElement->IntAttribute("level");

		m_enemies.emplace_back(new Enemy(name, appearance, level));

		m_enemies.back()->calculateAllStats(
			enemyElement->FirstChildElement("stats")->IntAttribute("agi"),
			enemyElement->FirstChildElement("stats")->IntAttribute("vit"),
			enemyElement->FirstChildElement("stats")->IntAttribute("dex"),
			enemyElement->FirstChildElement("stats")->IntAttribute("str"),
			enemyElement->FirstChildElement("stats")->IntAttribute("wis"),
			enemyElement->FirstChildElement("stats")->IntAttribute("int")
		);

		tinyxml2::XMLElement *itemElement = enemyElement->FirstChildElement("item");
		while(itemElement) {
			u16 id, count;
			double chance;

			id = itemElement->IntAttribute("id");
			count = itemElement->IntAttribute("count");
			chance = itemElement->DoubleAttribute("chance");

			if(itemElement->Attribute("type", "Item")) {
				m_enemies.back()->loot()->addItem(id, count, chance);
			}
			else if(itemElement->Attribute("type", "Armor")) {
				m_enemies.back()->loot()->addArmor(id, count, chance);
			}
			else if(itemElement->Attribute("type", "Weapon")) {
				m_enemies.back()->loot()->addWeapon(id, count, chance);
			}

			itemElement = itemElement->NextSiblingElement("item");
		}

		enemyElement = enemyElement->NextSiblingElement("enemy");
	}
}

