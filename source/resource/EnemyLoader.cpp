/*
 * =====================================================================================
 *
 *       Filename:  EnemyLoader.cpp
 *
 *    Description:
 *
 *        Created:  17/02/2019 21:02:26
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/IntTypes.hpp>
#include <gk/resource/ResourceHandler.hpp>

#include "Enemy.hpp"
#include "EnemyLoader.hpp"

void EnemyLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	int enemyCount = 0;
	tinyxml2::XMLElement *enemyElement = doc.FirstChildElement("enemies").FirstChildElement("enemy").ToElement();
	while(enemyElement) {
		std::string name, appearance;
		u8 level;

		name = enemyElement->Attribute("name");
		appearance = std::string("texture-battler-") + enemyElement->Attribute("appearance");

		level = enemyElement->IntAttribute("level");

		Enemy &enemy = handler.add<Enemy>("enemy-" + std::to_string(enemyCount),
				name, appearance, level);

		enemy.calculateAllStats(
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
				enemy.loot().addItem(id, count, chance);
			}
			else if(itemElement->Attribute("type", "Armor")) {
				enemy.loot().addArmor(id, count, chance);
			}
			else if(itemElement->Attribute("type", "Weapon")) {
				enemy.loot().addWeapon(id, count, chance);
			}

			itemElement = itemElement->NextSiblingElement("item");
		}

		enemyCount++;

		enemyElement = enemyElement->NextSiblingElement("enemy");
	}
}

