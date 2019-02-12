/*
 * =====================================================================================
 *
 *       Filename:  EventManager.cpp
 *
 *    Description:
 *
 *        Created:  24/05/2014 13:22:42
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "LuaHandler.hpp"
#include "EventManager.hpp"

template<>
EventManager *Singleton<EventManager>::s_instance = nullptr;

void EventManager::init() {
	loadLibs();

	initEvents();
}

void EventManager::loadLibs() {
	LuaHandler::getInstance().doFile("data/lualibs/LuaEvent.lua");
	LuaHandler::getInstance().doFile("data/lualibs/ChestEvent.lua");
}

void EventManager::initEvents() {
	XMLFile doc("data/config/events.xml");

	tinyxml2::XMLElement *eventElement = doc.FirstChildElement("events").FirstChildElement("event").ToElement();
	while(eventElement) {
		std::string eventType = eventElement->Attribute("type");

		if(eventType == "Character") {
			loadCharacterEvent(eventElement);
		}
		else if(eventType == "Chest") {
			loadChestEvent(eventElement);
		} else {
			warning("Event type %s not recognized.", eventType.c_str());
		}

		eventElement = eventElement->NextSiblingElement("event");
	}
}

void EventManager::loadCharacterEvent(tinyxml2::XMLElement *characterElement) {
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

	m_events[name] = std::make_unique<Event>(
		name, std::string("graphics/characters/") + appearance + ".png",
		x * 32, y * 32, direction, solid, frameWidth, frameHeight
	);
}

void EventManager::loadChestEvent(tinyxml2::XMLElement *chestElement) {
	std::string name;
	u16 x, y, chestType;

	name = chestElement->Attribute("name");

	x = chestElement->IntAttribute("x");
	y = chestElement->IntAttribute("y");

	chestType = chestElement->IntAttribute("chestType");

	m_events[name] = std::make_unique<Event>(
		name, "graphics/events/Chest01.png",
		x * 32, y * 32, chestType, true
	);
}

