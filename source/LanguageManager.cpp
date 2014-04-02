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
	if(xml.LoadFile(std::string(std::string("data/locale/") + language + std::string(".xml")).c_str()) != 0) {
		error("Failed to load locale data: %s", language.c_str());
		exit(EXIT_FAILURE);
	}
	
	XMLHandle doc(&xml);
	
	XMLElement *wordElement = doc.FirstChildElement("language").FirstChildElement("word").ToElement();
	while(wordElement) {
		text[wordElement->Attribute("id")] = wordElement->Attribute("text");
		wordElement = wordElement->NextSiblingElement("word");
	}
}

std::string _t(std::string str) {
	return LanguageManager::text[str];
}

