/*
 * =====================================================================================
 *
 *       Filename:  ItemLoader.cpp
 *
 *    Description:
 *
 *        Created:  17/02/2019 21:50:30
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/resource/ResourceHandler.hpp>

#include "Item.hpp"
#include "ItemLoader.hpp"
#include "ResourceHelper.hpp"

void ItemLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	tinyxml2::XMLElement *itemElement = doc.FirstChildElement("items").FirstChildElement("item").ToElement();
	u16 id = 0;
	while(itemElement) {
		int effect;

		Item &item = handler.add<Item>("item-" + std::to_string(id),
			"Item" + std::to_string(id),
			"Item" + std::to_string(id) + "Desc",
			"texture-item-" + std::to_string(id)
		);

		item.setID(id);

		if(!itemElement->QueryIntAttribute("effect", &effect)) {
			item.setEffect(effect);
		}

		itemElement = itemElement->NextSiblingElement("item");
		id++;
	}
}

