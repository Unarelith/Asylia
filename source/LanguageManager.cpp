/*
 * =====================================================================================
 *
 *       Filename:  LanguageManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/04/2014 13:51:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

std::map<std::string, std::string> LanguageManager::text;

void LanguageManager::init(std::string language) {
	if(text.size() > 0) text.clear();
	
	XMLDocument xml;
	int code = xml.LoadFile(std::string(std::string("data/locale/") + language + std::string(".xml")).c_str());
	if(code == XML_ERROR_FILE_NOT_FOUND) {
		warn("Locale \"%s\" not supported. Using \"en-us\" by default.", language.c_str());
		init("en-us");
		return;
	}
	else if(code != XML_NO_ERROR) {
		error("Failed to load locale data: %s (CODE: %d)", language.c_str(), code);
		exit(EXIT_FAILURE);
	}
	
	XMLHandle doc(&xml);
	
	/* INTERFACE */
	XMLElement *textElement = doc.FirstChildElement("language").FirstChildElement("text").ToElement();
	while(textElement) {
		text[textElement->Attribute("id")] = textElement->Attribute("text");
		textElement = textElement->NextSiblingElement("text");
	}
	
	/* EVENTS */
	XMLElement *eventElement = doc.FirstChildElement("language").FirstChildElement("event").ToElement();
	u16 id = eventElement->IntAttribute("id");
	u8 counter = 0;
	while(eventElement) {
		XMLElement *eventMessageElement = eventElement->FirstChildElement("message");
		while(eventMessageElement) {
			text[std::string("event") + to_string(id) + "-" + to_string(counter)] = eventMessageElement->Attribute("text");
			eventMessageElement = eventMessageElement->NextSiblingElement("message");
			counter++;
		}
		counter = 0;
		eventElement = eventElement->NextSiblingElement("event");
	}
	
	/* ITEMS */
	XMLElement *itemElement = doc.FirstChildElement("language").FirstChildElement("item").ToElement();
	counter = 0;
	while(itemElement) {
		std::string name, description;
		
		name = itemElement->Attribute("name");
		
		XMLElement *itemDescriptionElement = itemElement->FirstChildElement("description");
		while(itemDescriptionElement) {
			description += itemDescriptionElement->Attribute("text");// + std::string("\n");
			
			itemDescriptionElement = itemDescriptionElement->NextSiblingElement("description");
		}
		
		text[std::string("Item") + to_string(counter)] = name;
		text[std::string("Item") + to_string(counter) + "Desc"] = description;
		
		itemElement = itemElement->NextSiblingElement("item");
		counter++;
	}
}

std::string LanguageManager::translate(std::string str) {
	return LanguageManager::text[str];
}

std::string _t(std::string str) {
	return LanguageManager::translate(str);
}

