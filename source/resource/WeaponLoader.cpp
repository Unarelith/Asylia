/*
 * =====================================================================================
 *
 *       Filename:  WeaponLoader.cpp
 *
 *    Description:
 *
 *        Created:  17/02/2019 21:51:10
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/resource/ResourceHandler.hpp>

#include "Weapon.hpp"
#include "WeaponLoader.hpp"

void WeaponLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	tinyxml2::XMLElement *weaponElement = doc.FirstChildElement("weapons").FirstChildElement("weapon").ToElement();
	u16 id = 0;
	while(weaponElement) {
		Weapon &weapon = handler.add<Weapon>("weapon-" + std::to_string(id),
			"Weapon" + std::to_string(id),
			"Weapon" + std::to_string(id) + "Desc",
			"graphics/weapons/" + std::to_string(id) + ".png",
			weaponElement->IntAttribute("damage"),
			weaponElement->DoubleAttribute("hitRate")
		);

		weapon.setID(id);

		weaponElement = weaponElement->NextSiblingElement("weapon");
		id++;
	}
}

