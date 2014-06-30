/*
 * =====================================================================================
 *
 *       Filename:  QuestObjective.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29/06/2014 23:09:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

QuestObjective::QuestObjective() {
	m_type = Type::Undefined;
}

QuestObjective::QuestObjective(u16 itemToBring, Item::Type type) {
	m_type = Type::BringItem;
	
	m_params.addIntParameter(itemToBring);
	m_params.addIntParameter(type);
}

QuestObjective::QuestObjective(u16 itemToGet, Item::Type type, u16 count) {
	m_type = Type::GetItem;
	
	m_params.addIntParameter(itemToGet);
	m_params.addIntParameter(type);
	m_params.addIntParameter(count);
}

QuestObjective::QuestObjective(u16 enemyToBeat, u16 count) {
	m_type = Type::BeatEnemy;
	
	m_params.addIntParameter(enemyToBeat);
	m_params.addIntParameter(count);
}

QuestObjective::QuestObjective(std::string eventToTalkTo) {
	m_type = Type::TalkToSomeone;
	
	m_params.addStringParameter(eventToTalkTo);
}

QuestObjective::~QuestObjective() {
}
