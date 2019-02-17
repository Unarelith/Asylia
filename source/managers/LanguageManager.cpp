/*
 * =====================================================================================
 *
 *       Filename:  LanguageManager.cpp
 *
 *    Description:
 *
 *        Created:  02/04/2014 13:51:40
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/IntTypes.hpp>
#include <gk/core/XMLFile.hpp>

#include "LanguageManager.hpp"

template<>
LanguageManager *Singleton<LanguageManager>::s_instance = nullptr;

void LanguageManager::init(const std::string &language) {
	if(m_text.size() > 0) m_text.clear();

	m_currentLanguage = language;

	gk::XMLFile doc(std::string(std::string("data/locale/") + language + ".xml").c_str());

	/* INTERFACE */
	tinyxml2::XMLElement *textElement = doc.FirstChildElement("language").FirstChildElement("text").ToElement();
	while(textElement) {
		m_text[textElement->Attribute("id")] = textElement->Attribute("text");
		textElement = textElement->NextSiblingElement("text");
	}

	/* EVENTS */
	tinyxml2::XMLElement *eventElement = doc.FirstChildElement("language").FirstChildElement("event").ToElement();
	std::string name;
	u8 counter = 0;
	while(eventElement) {
		name = eventElement->Attribute("name");
		tinyxml2::XMLElement *eventMessageElement = eventElement->FirstChildElement("message");
		while(eventMessageElement) {
			m_text[name + "-" + std::to_string(counter)] = eventMessageElement->Attribute("text");
			eventMessageElement = eventMessageElement->NextSiblingElement("message");
			counter++;
		}
		counter = 0;
		eventElement = eventElement->NextSiblingElement("event");
	}

	/* ITEMS */
	tinyxml2::XMLElement *itemElement = doc.FirstChildElement("language").FirstChildElement("item").ToElement();
	counter = 0;
	while(itemElement) {
		m_text[std::string("Item") + std::to_string(counter)] = itemElement->Attribute("name");
		m_text[std::string("Item") + std::to_string(counter) + "Desc"] = itemElement->Attribute("description");

		itemElement = itemElement->NextSiblingElement("item");
		counter++;
	}

	/* ARMORS */
	tinyxml2::XMLElement *armorElement = doc.FirstChildElement("language").FirstChildElement("armor").ToElement();
	counter = 0;
	while(armorElement) {
		m_text[std::string("Armor") + std::to_string(counter)] = armorElement->Attribute("name");
		m_text[std::string("Armor") + std::to_string(counter) + "Desc"] = armorElement->Attribute("description");

		armorElement = armorElement->NextSiblingElement("armor");
		counter++;
	}

	/* WEAPONS */
	tinyxml2::XMLElement *weaponElement = doc.FirstChildElement("language").FirstChildElement("weapon").ToElement();
	counter = 0;
	while(weaponElement) {
		m_text[std::string("Weapon") + std::to_string(counter)] = weaponElement->Attribute("name");
		m_text[std::string("Weapon") + std::to_string(counter) + "Desc"] = weaponElement->Attribute("description");

		weaponElement = weaponElement->NextSiblingElement("weapon");
		counter++;
	}

	/* SKILLS */
	tinyxml2::XMLElement *skillElement = doc.FirstChildElement("language").FirstChildElement("skill").ToElement();
	counter = 0;
	while(skillElement) {
		m_text[std::string("Skill") + std::to_string(counter)] = skillElement->Attribute("name");
		m_text[std::string("Skill") + std::to_string(counter) + "Desc"] = skillElement->Attribute("description");

		skillElement = skillElement->NextSiblingElement("skill");
		counter++;
	}

	/* QUESTS */
	tinyxml2::XMLElement *questElement = doc.FirstChildElement("language").FirstChildElement("quest").ToElement();
	counter = 0;
	while(questElement) {
		m_text[std::string("Quest") + std::to_string(counter)] = questElement->Attribute("name");
		m_text[std::string("Quest") + std::to_string(counter) + "Desc"] = questElement->Attribute("description");

		tinyxml2::XMLElement *objectiveElement = questElement->FirstChildElement("objective");
		u16 id = 0;
		while(objectiveElement) {
			m_text[std::string("Quest") + std::to_string(counter) + "_Obj" + std::to_string(id) + "Desc"] = objectiveElement->Attribute("description");

			objectiveElement = objectiveElement->NextSiblingElement("objective");
			id++;
		}

		questElement = questElement->NextSiblingElement("quest");
		counter++;
	}
}

const std::string &LanguageManager::translate(const std::string &str) {
	const std::string &translated = m_text[str];
	if(translated == "") return str;
	return translated;
}

const std::string &_t(const std::string &str) {
	return LanguageManager::getInstance().translate(str);
}

