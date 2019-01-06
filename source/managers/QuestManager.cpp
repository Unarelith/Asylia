/*
 * =====================================================================================
 *
 *       Filename:  QuestManager.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  30/06/2014 16:26:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

std::vector<Quest*> QuestManager::quests;

void QuestManager::init() {
	XMLFile doc("data/config/quests.xml");

	XMLElement *questElement = doc.FirstChildElement("quests").FirstChildElement("quest").ToElement();
	while(questElement) {
		u16 exp, gold;

		exp = questElement->IntAttribute("exp");
		gold = questElement->IntAttribute("gold");

		quests.push_back(new Quest(exp, gold));

		XMLElement *itemElement = questElement->FirstChildElement("item");
		while(itemElement) {
			std::string type = itemElement->Attribute("type");

			u16 id = itemElement->IntAttribute("id");
			u16 count = itemElement->IntAttribute("count");

			if(type == "Item") {
				quests.back()->items()->addItem(id, count);
			}
			else if(type == "Weapon") {
				quests.back()->items()->addWeapon(id, count);
			}
			else if(type == "Armor") {
				quests.back()->items()->addArmor(id, count);
			}

			itemElement = itemElement->NextSiblingElement("item");
		}

		XMLElement *objectiveElement = questElement->FirstChildElement("objectives")->FirstChildElement("objective");
		while(objectiveElement) {
			std::string type = objectiveElement->Attribute("type");

			if(type == "BringItem") {
				u16 type = objectiveElement->IntAttribute("itemtype");
				u16 id = objectiveElement->IntAttribute("id");
				std::string event = objectiveElement->Attribute("event");

				quests.back()->addObjective(new QuestObjective(id, (Item::Type)type, event));
			}
			else if(type == "GetItem") {
				u16 type = objectiveElement->IntAttribute("itemtype");
				u16 id = objectiveElement->IntAttribute("id");
				u16 count = objectiveElement->IntAttribute("count");

				quests.back()->addObjective(new QuestObjective(id, (Item::Type)type, count));
			}
			else if(type == "BeatEnemy") {
				u16 id = objectiveElement->IntAttribute("id");
				u16 count = objectiveElement->IntAttribute("count");

				quests.back()->addObjective(new QuestObjective(id, count));
			}
			else if(type == "TalkToSomeone") {
				std::string eventName = objectiveElement->Attribute("name");

				quests.back()->addObjective(new QuestObjective(eventName));
			}

			objectiveElement = objectiveElement->NextSiblingElement("objective");
		}

		questElement = questElement->NextSiblingElement("quest");
	}
}

void QuestManager::free() {
	while(quests.size() != 0) {
		delete quests.back();
		quests.pop_back();
	}
}

