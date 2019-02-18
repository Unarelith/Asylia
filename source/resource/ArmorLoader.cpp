/*
 * =====================================================================================
 *
 *       Filename:  ArmorLoader.cpp
 *
 *    Description:
 *
 *        Created:  17/02/2019 21:50:55
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/resource/ResourceHandler.hpp>

#include "Armor.hpp"
#include "ArmorLoader.hpp"

void ArmorLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	tinyxml2::XMLElement *armorElement = doc.FirstChildElement("armors").FirstChildElement("armor").ToElement();
	u16 id = 0;
	while(armorElement) {
		Armor &armor = handler.add<Armor>("armor-" + std::to_string(id),
			"Armor" + std::to_string(id),
			"Armor" + std::to_string(id) + "Desc",
			"resources/graphics/armors/" + std::to_string(id) + ".png",
			armorElement->IntAttribute("slot"),
			armorElement->IntAttribute("defense")
		);

		armor.setID(id);

		armorElement = armorElement->NextSiblingElement("armor");
		id++;
	}
}

