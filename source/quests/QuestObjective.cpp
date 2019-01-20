/*
 * =====================================================================================
 *
 *       Filename:  QuestObjective.cpp
 *
 *    Description:
 *
 *        Created:  29/06/2014 23:09:56
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

QuestObjective::QuestObjective() {
	m_type = Type::Undefined;
}

QuestObjective::QuestObjective(u16 itemToBring, Item::Type type, std::string eventToBringTo) {
	m_type = Type::BringItem;

	m_params.addIntParameter(itemToBring);
	m_params.addIntParameter(type);
	m_params.addStringParameter(eventToBringTo);
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

