/*
 * =====================================================================================
 *
 *       Filename:  QuestManager.cpp
 *
 *    Description:
 *
 *        Created:  30/06/2014 16:26:01
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "QuestManager.hpp"
#include "XMLFile.hpp"

template<>
QuestManager *Singleton<QuestManager>::s_instance = nullptr;

void QuestManager::init() {
	XMLFile doc("data/config/quests.xml");

	tinyxml2::XMLElement *questElement = doc.FirstChildElement("quests").FirstChildElement("quest").ToElement();
	while(questElement) {
		u16 exp, gold;

		exp = questElement->IntAttribute("exp");
		gold = questElement->IntAttribute("gold");

		m_quests.emplace_back(new Quest(exp, gold));

		tinyxml2::XMLElement *itemElement = questElement->FirstChildElement("item");
		while(itemElement) {
			std::string type = itemElement->Attribute("type");

			u16 id = itemElement->IntAttribute("id");
			u16 count = itemElement->IntAttribute("count");

			if(type == "Item") {
				m_quests.back()->items()->addItem(id, count);
			}
			else if(type == "Weapon") {
				m_quests.back()->items()->addWeapon(id, count);
			}
			else if(type == "Armor") {
				m_quests.back()->items()->addArmor(id, count);
			}

			itemElement = itemElement->NextSiblingElement("item");
		}

		tinyxml2::XMLElement *objectiveElement = questElement->FirstChildElement("objectives")->FirstChildElement("objective");
		while(objectiveElement) {
			std::string type = objectiveElement->Attribute("type");

			if(type == "BringItem") {
				u16 type = objectiveElement->IntAttribute("itemtype");
				u16 id = objectiveElement->IntAttribute("id");
				std::string event = objectiveElement->Attribute("event");

				m_quests.back()->addObjective(new QuestObjective(id, (Item::Type)type, event));
			}
			else if(type == "GetItem") {
				u16 type = objectiveElement->IntAttribute("itemtype");
				u16 id = objectiveElement->IntAttribute("id");
				u16 count = objectiveElement->IntAttribute("count");

				m_quests.back()->addObjective(new QuestObjective(id, (Item::Type)type, count));
			}
			else if(type == "BeatEnemy") {
				u16 id = objectiveElement->IntAttribute("id");
				u16 count = objectiveElement->IntAttribute("count");

				m_quests.back()->addObjective(new QuestObjective(id, count));
			}
			else if(type == "TalkToSomeone") {
				std::string eventName = objectiveElement->Attribute("name");

				m_quests.back()->addObjective(new QuestObjective(eventName));
			}

			objectiveElement = objectiveElement->NextSiblingElement("objective");
		}

		questElement = questElement->NextSiblingElement("quest");
	}
}

