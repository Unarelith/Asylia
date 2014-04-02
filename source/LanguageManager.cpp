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
	
	XMLElement *textElement = doc.FirstChildElement("language").FirstChildElement("text").ToElement();
	while(textElement) {
		text[textElement->Attribute("id")] = textElement->Attribute("text");
		textElement = textElement->NextSiblingElement("text");
	}
	
	XMLElement *npcElement = doc.FirstChildElement("language").FirstChildElement("npc").ToElement();
	u16 id = npcElement->IntAttribute("id");
	u8 counter = 0;
	while(npcElement) {
		XMLElement *npcMessageElement = npcElement->FirstChildElement("message");
		while(npcMessageElement) {
			text[std::string("NPC") + to_string(id) + "-" + to_string(counter)] = npcMessageElement->Attribute("text");
			npcMessageElement = npcMessageElement->NextSiblingElement("message");
			counter++;
		}
		counter = 0;
		npcElement = npcElement->NextSiblingElement("npc");
	}
}

std::string LanguageManager::translate(std::string str) {
	return LanguageManager::text[str];
}

std::string _t(std::string str) {
	return LanguageManager::translate(str);
}

