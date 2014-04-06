/*
 * =====================================================================================
 *
 *       Filename:  ItemManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2014 19:40:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

std::vector<Item*> ItemManager::items;
std::vector<Armor*> ItemManager::armors;
std::vector<Weapon*> ItemManager::weapons;

void ItemManager::init() {
	loadItems();
	loadArmors();
	loadWeapons();
}

void ItemManager::loadItems() {
	XMLDocument xml;
	int code = xml.LoadFile("data/config/items.xml");
	if(code != 0) {
		error("Failed to load items data. (CODE: %d)", code);
		exit(EXIT_FAILURE);
	}
	
	XMLHandle doc(&xml);
	
	XMLElement *itemElement = doc.FirstChildElement("items").FirstChildElement("item").ToElement();
	u8 id = 0;
	while(itemElement) {
		items.push_back(new Item(
			std::string("Item") + to_string(id),
			std::string("Item") + to_string(id) + "Desc",
			itemElement->IntAttribute("level"),
			std::string("graphics/items/") + to_string(id) + ".png"
		));
		
		itemElement = itemElement->NextSiblingElement("item");
		id++;
	}
}

void ItemManager::loadArmors() {
	XMLDocument xml;
	int code = xml.LoadFile("data/config/armors.xml");
	if(code != 0) {
		error("Failed to load armors data. (CODE: %d)", code);
		exit(EXIT_FAILURE);
	}
	
	XMLHandle doc(&xml);
	
	XMLElement *armorElement = doc.FirstChildElement("armors").FirstChildElement("armor").ToElement();
	u8 id = 0;
	while(armorElement) {
		armors.push_back(new Armor(
			std::string("Armor") + to_string(id),
			std::string("Armor") + to_string(id) + "Desc",
			armorElement->IntAttribute("level"),
			std::string("graphics/armors/") + to_string(id) + ".png",
			armorElement->IntAttribute("slot"),
			armorElement->IntAttribute("defense")
		));
		
		armorElement = armorElement->NextSiblingElement("armor");
		id++;
	}
}

void ItemManager::loadWeapons() {
	XMLDocument xml;
	int code = xml.LoadFile("data/config/weapons.xml");
	if(code != 0) {
		error("Failed to load weapons data. (CODE: %d)", code);
		exit(EXIT_FAILURE);
	}
	
	XMLHandle doc(&xml);
	
	XMLElement *weaponElement = doc.FirstChildElement("weapons").FirstChildElement("weapon").ToElement();
	u8 id = 0;
	while(weaponElement) {
		weapons.push_back(new Weapon(
			std::string("Weapon") + to_string(id),
			std::string("Weapon") + to_string(id) + "Desc",
			weaponElement->IntAttribute("level"),
			std::string("graphics/weapons/") + to_string(id) + ".png",
			weaponElement->IntAttribute("damage"),
			weaponElement->DoubleAttribute("hitRate")
		));
		
		weaponElement = weaponElement->NextSiblingElement("weapon");
		id++;
	}
}

