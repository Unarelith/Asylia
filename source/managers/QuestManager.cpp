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
	
	XMLElement *questElement = doc.FirstChildElement("quests").FirstChildElement("quest")->ToElement();
	while(questElement) {
		questElement = questElement->NextSiblingElement("quest");
	}
}

void QuestManager::free() {
	while(quests.size() != 0) {
		delete quests.back();
		quests.pop_back();
	}
}

