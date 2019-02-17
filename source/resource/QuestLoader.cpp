/*
 * =====================================================================================
 *
 *       Filename:  QuestLoader.cpp
 *
 *    Description:
 *
 *        Created:  17/02/2019 22:38:12
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/resource/ResourceHandler.hpp>

#include "Quest.hpp"
#include "QuestLoader.hpp"

void QuestLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	u16 id = 0;
	tinyxml2::XMLElement *questElement = doc.FirstChildElement("quests").FirstChildElement("quest").ToElement();
	while(questElement) {
		u16 exp, gold;

		exp = questElement->IntAttribute("exp");
		gold = questElement->IntAttribute("gold");

		Quest &quest = handler.add<Quest>("quest-" + std::to_string(id++), exp, gold);

		tinyxml2::XMLElement *itemElement = questElement->FirstChildElement("item");
		while(itemElement) {
			std::string type = itemElement->Attribute("type");

			u16 id = itemElement->IntAttribute("id");
			u16 count = itemElement->IntAttribute("count");

			if(type == "Item") {
				quest.items()->addItem(id, count);
			}
			else if(type == "Weapon") {
				quest.items()->addWeapon(id, count);
			}
			else if(type == "Armor") {
				quest.items()->addArmor(id, count);
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

				quest.addObjective(new QuestObjective(id, (Item::Type)type, event));
			}
			else if(type == "GetItem") {
				u16 type = objectiveElement->IntAttribute("itemtype");
				u16 id = objectiveElement->IntAttribute("id");
				u16 count = objectiveElement->IntAttribute("count");

				quest.addObjective(new QuestObjective(id, (Item::Type)type, count));
			}
			else if(type == "BeatEnemy") {
				u16 id = objectiveElement->IntAttribute("id");
				u16 count = objectiveElement->IntAttribute("count");

				quest.addObjective(new QuestObjective(id, count));
			}
			else if(type == "TalkToSomeone") {
				std::string eventName = objectiveElement->Attribute("name");

				quest.addObjective(new QuestObjective(eventName));
			}

			objectiveElement = objectiveElement->NextSiblingElement("objective");
		}

		questElement = questElement->NextSiblingElement("quest");
	}
}

