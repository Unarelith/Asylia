/*
 * =====================================================================================
 *
 *       Filename:  EventLoader.cpp
 *
 *    Description:
 *
 *        Created:  18/02/2019 08:23:30
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "LuaHandler.hpp"
#include "Event.hpp"
#include "EventLoader.hpp"

void EventLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	LuaHandler::getInstance().doFile("resources/lualibs/LuaEvent.lua");
	LuaHandler::getInstance().doFile("resources/lualibs/ChestEvent.lua");

	gk::XMLFile doc(xmlFilename);

	tinyxml2::XMLElement *tilemapElement = doc.FirstChildElement("events").FirstChildElement("tilemap").ToElement();
	while (tilemapElement) {
		tinyxml2::XMLElement *eventElement = tilemapElement->FirstChildElement("event");
		while(eventElement) {
			std::string eventType = eventElement->Attribute("type");

			if(eventType == "Character") {
				loadCharacterEvent(eventElement, handler);
			}
			else if(eventType == "Chest") {
				loadChestEvent(eventElement, handler);
			} else {
				DEBUG("Warning: Event type", eventType, "not recognized.");
			}

			eventElement = eventElement->NextSiblingElement("event");
		}

		tilemapElement = tilemapElement->NextSiblingElement("tilemap");
	}
}

void EventLoader::loadCharacterEvent(tinyxml2::XMLElement *characterElement, gk::ResourceHandler &handler) {
	std::string name, appearance;
	u16 x, y, direction;
	int frameWidth, frameHeight;
	bool solid;

	name = characterElement->Attribute("name");
	appearance = characterElement->Attribute("appearance");

	x = characterElement->IntAttribute("x");
	y = characterElement->IntAttribute("y");

	direction = characterElement->IntAttribute("direction");

	if(characterElement->QueryBoolAttribute("solid", &solid)) {
		solid = true;
	}

	if(characterElement->QueryIntAttribute("frameWidth", &frameWidth)) {
		frameWidth = 32;
	}

	if(characterElement->QueryIntAttribute("frameHeight", &frameHeight)) {
		frameHeight = 48;
	}

	handler.add<Event>("event-" + name,
		name, std::string("texture-character-") + appearance,
		x * 32, y * 32, direction, solid, frameWidth, frameHeight
	);
}

void EventLoader::loadChestEvent(tinyxml2::XMLElement *chestElement, gk::ResourceHandler &handler) {
	std::string name;
	u16 x, y, chestType;

	name = chestElement->Attribute("name");

	x = chestElement->IntAttribute("x");
	y = chestElement->IntAttribute("y");

	chestType = chestElement->IntAttribute("chestType");

	handler.add<Event>("event-" + name,
		name, "texture-event-Chest01",
		x * 32, y * 32, chestType, true
	);
}


