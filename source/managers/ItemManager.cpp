/*
 * =====================================================================================
 *
 *       Filename:  ItemManager.cpp
 *
 *    Description:
 *
 *        Created:  05/04/2014 19:40:15
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

std::vector<Item*> ItemManager::items;
std::vector<Armor*> ItemManager::armors;
std::vector<Weapon*> ItemManager::weapons;
std::vector<Skill*> ItemManager::skills;

void ItemManager::init() {
	loadItems();
	loadArmors();
	loadWeapons();
	loadSkills();
}

void ItemManager::free() {
	while(items.size() != 0) {
		delete items.back();
		items.pop_back();
	}

	while(armors.size() != 0) {
		delete armors.back();
		armors.pop_back();
	}

	while(weapons.size() != 0) {
		delete weapons.back();
		weapons.pop_back();
	}

	while(skills.size() != 0) {
		delete skills.back();
		skills.pop_back();
	}
}

void ItemManager::loadItems() {
	XMLFile doc("data/config/items.xml");

	XMLElement *itemElement = doc.FirstChildElement("items").FirstChildElement("item").ToElement();
	u8 id = 0;
	while(itemElement) {
		const char *animation;
		int effect;

		animation = itemElement->Attribute("animation");
		if(!animation) animation = "";

		items.push_back(new Item(
			std::string("Item") + to_string(id),
			std::string("Item") + to_string(id) + "Desc",
			std::string("graphics/items/") + to_string(id) + ".png",
			AnimationManager::getAnimationByName(animation)
		));

		items.back()->setID(id);

		if(itemElement->QueryIntAttribute("effect", &effect) == XML_NO_ERROR) {
			items.back()->setEffect(effect);
		}

		itemElement = itemElement->NextSiblingElement("item");
		id++;
	}
}

void ItemManager::loadArmors() {
	XMLFile doc("data/config/armors.xml");

	XMLElement *armorElement = doc.FirstChildElement("armors").FirstChildElement("armor").ToElement();
	u8 id = 0;
	while(armorElement) {
		armors.push_back(new Armor(
			std::string("Armor") + to_string(id),
			std::string("Armor") + to_string(id) + "Desc",
			std::string("graphics/armors/") + to_string(id) + ".png",
			armorElement->IntAttribute("slot"),
			armorElement->IntAttribute("defense")
		));

		armors.back()->setID(id);

		armorElement = armorElement->NextSiblingElement("armor");
		id++;
	}
}

void ItemManager::loadWeapons() {
	XMLFile doc("data/config/weapons.xml");

	XMLElement *weaponElement = doc.FirstChildElement("weapons").FirstChildElement("weapon").ToElement();
	u8 id = 0;
	while(weaponElement) {
		weapons.push_back(new Weapon(
			std::string("Weapon") + to_string(id),
			std::string("Weapon") + to_string(id) + "Desc",
			std::string("graphics/weapons/") + to_string(id) + ".png",
			weaponElement->IntAttribute("damage"),
			weaponElement->DoubleAttribute("hitRate")
		));

		weapons.back()->setID(id);

		weaponElement = weaponElement->NextSiblingElement("weapon");
		id++;
	}
}

void ItemManager::loadSkills() {
	XMLFile doc("data/config/skills.xml");

	XMLElement *skillElement = doc.FirstChildElement("skills").FirstChildElement("skill").ToElement();
	u8 id = 0;
	while(skillElement) {
		const char *animation;

		animation = skillElement->Attribute("animation");
		if(!animation) animation = "";

		skills.push_back(new Skill(
			std::string("Skill") + to_string(id),
			std::string("Skill") + to_string(id) + "Desc",
			std::string("graphics/skills/") + to_string(id) + ".png",
			AnimationManager::getAnimationByName(animation),
			skillElement->IntAttribute("damage"),
			skillElement->DoubleAttribute("hitRate")
		));

		skills.back()->setID(id);

		skillElement = skillElement->NextSiblingElement("skill");
		id++;
	}
}

