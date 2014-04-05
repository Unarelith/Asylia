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

void ItemManager::init() {
	loadItems();
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

