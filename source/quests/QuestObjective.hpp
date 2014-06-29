/*
 * =====================================================================================
 *
 *       Filename:  QuestObjective.hpp
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
}

QuestObjective::QuestObjective(u16 itemToGet, Item::Type type, u16 count) {
	m_type = Type::GetItem;
}

QuestObjective::QuestObjective(u16 enemyToBeat, u16 count) {
	m_type = Type::BeatEnemy;
}

QuestObjective::QuestObjective(std::string eventToTalkTo) {
	m_type = Type::TalkToSomeone;
}

QuestObjective::~QuestObjective() {
}

