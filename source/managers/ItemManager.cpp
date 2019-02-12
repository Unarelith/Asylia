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
#include "AnimationManager.hpp"
#include "ItemManager.hpp"
#include "XMLFile.hpp"

template<>
ItemManager *Singleton<ItemManager>::s_instance = nullptr;

void ItemManager::init() {
	loadItems();
	loadArmors();
	loadWeapons();
	loadSkills();
}

void ItemManager::loadItems() {
	XMLFile doc("data/config/items.xml");

	tinyxml2::XMLElement *itemElement = doc.FirstChildElement("items").FirstChildElement("item").ToElement();
	u8 id = 0;
	while(itemElement) {
		const char *animation;
		int effect;

		animation = itemElement->Attribute("animation");
		if(!animation) animation = "";

		m_items.emplace_back(new Item(
			std::string("Item") + std::to_string(id),
			std::string("Item") + std::to_string(id) + "Desc",
			std::string("graphics/items/") + std::to_string(id) + ".png",
			AnimationManager::getInstance().getAnimationByName(animation)
		));

		m_items.back()->setID(id);

		if(!itemElement->QueryIntAttribute("effect", &effect)) {
			m_items.back()->setEffect(effect);
		}

		itemElement = itemElement->NextSiblingElement("item");
		id++;
	}
}

void ItemManager::loadArmors() {
	XMLFile doc("data/config/armors.xml");

	tinyxml2::XMLElement *armorElement = doc.FirstChildElement("armors").FirstChildElement("armor").ToElement();
	u8 id = 0;
	while(armorElement) {
		m_armors.emplace_back(new Armor(
			std::string("Armor") + std::to_string(id),
			std::string("Armor") + std::to_string(id) + "Desc",
			std::string("graphics/armors/") + std::to_string(id) + ".png",
			armorElement->IntAttribute("slot"),
			armorElement->IntAttribute("defense")
		));

		m_armors.back()->setID(id);

		armorElement = armorElement->NextSiblingElement("armor");
		id++;
	}
}

void ItemManager::loadWeapons() {
	XMLFile doc("data/config/weapons.xml");

	tinyxml2::XMLElement *weaponElement = doc.FirstChildElement("weapons").FirstChildElement("weapon").ToElement();
	u8 id = 0;
	while(weaponElement) {
		m_weapons.emplace_back(new Weapon(
			std::string("Weapon") + std::to_string(id),
			std::string("Weapon") + std::to_string(id) + "Desc",
			std::string("graphics/weapons/") + std::to_string(id) + ".png",
			weaponElement->IntAttribute("damage"),
			weaponElement->DoubleAttribute("hitRate")
		));

		m_weapons.back()->setID(id);

		weaponElement = weaponElement->NextSiblingElement("weapon");
		id++;
	}
}

void ItemManager::loadSkills() {
	XMLFile doc("data/config/skills.xml");

	tinyxml2::XMLElement *skillElement = doc.FirstChildElement("skills").FirstChildElement("skill").ToElement();
	u8 id = 0;
	while(skillElement) {
		const char *animation;

		animation = skillElement->Attribute("animation");
		if(!animation) animation = "";

		m_skills.emplace_back(new Skill(
			std::string("Skill") + std::to_string(id),
			std::string("Skill") + std::to_string(id) + "Desc",
			std::string("graphics/skills/") + std::to_string(id) + ".png",
			AnimationManager::getInstance().getAnimationByName(animation),
			skillElement->IntAttribute("damage"),
			skillElement->DoubleAttribute("hitRate")
		));

		m_skills.back()->setID(id);

		skillElement = skillElement->NextSiblingElement("skill");
		id++;
	}
}

