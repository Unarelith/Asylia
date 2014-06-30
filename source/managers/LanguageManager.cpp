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
std::string LanguageManager::currentLanguage;

void LanguageManager::init(std::string language) {
	if(text.size() > 0) text.clear();
	
	currentLanguage = language;
	
	XMLFile doc(std::string(std::string("data/locale/") + language + ".xml").c_str());
	
	/* INTERFACE */
	XMLElement *textElement = doc.FirstChildElement("language").FirstChildElement("text").ToElement();
	while(textElement) {
		text[textElement->Attribute("id")] = textElement->Attribute("text");
		textElement = textElement->NextSiblingElement("text");
	}
	
	/* EVENTS */
	XMLElement *eventElement = doc.FirstChildElement("language").FirstChildElement("event").ToElement();
	std::string name;
	u8 counter = 0;
	while(eventElement) {
		name = eventElement->Attribute("name");
		XMLElement *eventMessageElement = eventElement->FirstChildElement("message");
		while(eventMessageElement) {
			text[name + "-" + to_string(counter)] = eventMessageElement->Attribute("text");
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
		text[std::string("Item") + to_string(counter)] = itemElement->Attribute("name");
		text[std::string("Item") + to_string(counter) + "Desc"] = itemElement->Attribute("description");
		
		itemElement = itemElement->NextSiblingElement("item");
		counter++;
	}
	
	/* ARMORS */
	XMLElement *armorElement = doc.FirstChildElement("language").FirstChildElement("armor").ToElement();
	counter = 0;
	while(armorElement) {
		text[std::string("Armor") + to_string(counter)] = armorElement->Attribute("name");
		text[std::string("Armor") + to_string(counter) + "Desc"] = armorElement->Attribute("description");
		
		armorElement = armorElement->NextSiblingElement("armor");
		counter++;
	}
	
	/* WEAPONS */
	XMLElement *weaponElement = doc.FirstChildElement("language").FirstChildElement("weapon").ToElement();
	counter = 0;
	while(weaponElement) {
		text[std::string("Weapon") + to_string(counter)] = weaponElement->Attribute("name");
		text[std::string("Weapon") + to_string(counter) + "Desc"] = weaponElement->Attribute("description");
		
		weaponElement = weaponElement->NextSiblingElement("weapon");
		counter++;
	}
	
	/* SKILLS */
	XMLElement *skillElement = doc.FirstChildElement("language").FirstChildElement("skill").ToElement();
	counter = 0;
	while(skillElement) {
		text[std::string("Skill") + to_string(counter)] = skillElement->Attribute("name");
		text[std::string("Skill") + to_string(counter) + "Desc"] = skillElement->Attribute("description");
		
		skillElement = skillElement->NextSiblingElement("skill");
		counter++;
	}
	
	/* QUESTS */
	XMLElement *questElement = doc.FirstChildElement("language").FirstChildElement("quest").ToElement();
	counter = 0;
	while(questElement) {
		text[std::string("Quest") + to_string(counter)] = questElement->Attribute("name");
		text[std::string("Quest") + to_string(counter) + "Desc"] = questElement->Attribute("description");
		
		XMLElement *objectiveElement = questElement->FirstChildElement("objective");
		u16 id = 0;
		while(objectiveElement) {
			text[std::string("Quest") + to_string(counter) + "_Obj" + to_string(id) + "Desc"] = objectiveElement->Attribute("description");
			
			objectiveElement = objectiveElement->NextSiblingElement("objective");
			id++;
		}
		
		questElement = questElement->NextSiblingElement("quest");
		counter++;
	}
}

std::string LanguageManager::translate(std::string str) {
	std::string translated = LanguageManager::text[str];
	if(translated == "") translated = str;
	return translated;
}

std::string _t(std::string str) {
	return LanguageManager::translate(str);
}

