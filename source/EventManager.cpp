/*
 * =====================================================================================
 *
 *       Filename:  EventManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  24/05/2014 13:22:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

std::map<std::string, Event*> EventManager::events;

void EventManager::init() {
	loadLibs();
	
	initEvents();
}

void EventManager::free() {
	for(auto &it : events) {
		delete it.second;
	}
	events.clear();
}

void EventManager::loadLibs() {
	LuaHandler::doFile("data/lualibs/CharacterEvent.lua");
	LuaHandler::doFile("data/lualibs/ChestEvent.lua");
}

void EventManager::initEvents() {
	XMLDocument xml;
	int code = xml.LoadFile("data/config/events.xml");
	if(code != 0) {
		error("Failed to load events data. (CODE: %d)", code);
		exit(EXIT_FAILURE);
	}
	
	XMLHandle doc(&xml);
	
	XMLElement *eventElement = doc.FirstChildElement("events").FirstChildElement("event").ToElement();
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

void EventManager::loadCharacterEvent(XMLElement *characterElement) {
	std::string name, appearance;
	u16 x, y, direction;
	bool solid;
	
	name = characterElement->Attribute("name");
	appearance = characterElement->Attribute("appearance");
	
	x = characterElement->IntAttribute("x");
	y = characterElement->IntAttribute("y");
	
	direction = characterElement->IntAttribute("direction");
	
	if(characterElement->QueryBoolAttribute("solid", &solid) != XML_NO_ERROR) {
		solid = true;
	}
	
	events[name] = new Event(
		name,
		std::string("graphics/characters/") + appearance + ".png",
		x * 32, y * 32, direction, solid
	);
}

void EventManager::loadChestEvent(XMLElement *chestElement) {
	
}

