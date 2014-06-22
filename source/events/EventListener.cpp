/*
 * =====================================================================================
 *
 *       Filename:  EventListener.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/06/2014 19:25:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

std::vector<std::pair<EventListener::Type, s32>> EventListener::actionHistory;

void EventListener::addBattleResult(u8 battleResult) {
	actionHistory.push_back(std::make_pair(Type::BattleResult, battleResult));
}

void EventListener::addMessageActivityAction(u8 pos) {
	actionHistory.push_back(std::make_pair(Type::MessageActivityAction, pos));
}

s32 EventListener::getLastValueOf(Type type) {
	for(auto it = actionHistory.rbegin() ; it != actionHistory.rend() ; it++) {
		if(it->first == type) {
			return it->second;
		}
	}
	return -1;
}
	
s8 EventListener::lastBattleResult() {
	return getLastValueOf(Type::BattleResult);
}

s8 EventListener::lastMessageActivityAction() {
	return getLastValueOf(Type::BattleResult);
}

