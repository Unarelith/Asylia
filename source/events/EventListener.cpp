/*
 * =====================================================================================
 *
 *       Filename:  EventListener.cpp
 *
 *    Description:
 *
 *        Created:  21/06/2014 19:25:50
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

std::vector<std::pair<EventListener::Type, s32>> EventListener::actionHistory;

void EventListener::addMessageStateAction(u8 pos) {
	actionHistory.push_back(std::make_pair(Type::MessageStateAction, pos));
}

void EventListener::addBattleResult(u8 battleResult) {
	actionHistory.push_back(std::make_pair(Type::BattleResult, battleResult));
}

s32 EventListener::getLastValueOf(Type type) {
	for(auto it = actionHistory.rbegin() ; it != actionHistory.rend() ; it++) {
		if(it->first == type) {
			return it->second;
		}
	}
	return -1;
}

s8 EventListener::lastMessageStateAction() {
	return getLastValueOf(Type::BattleResult);
}

s8 EventListener::lastBattleResult() {
	return getLastValueOf(Type::BattleResult);
}

