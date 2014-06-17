/*
 * =====================================================================================
 *
 *       Filename:  EventInterpreter.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  17/06/2014 21:12:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

std::map<std::string, std::queue<EventAction*>> EventInterpreter::actions;

void EventInterpreter::free() {
	for(auto &it : actions) {
		while(it.second.size() != 0) {
			delete it.second.front();
			it.second.pop();
		}
	}
	actions.clear();
}

void EventInterpreter::addActionToQueue(std::string eventName, u16 actionID, ParameterList parameters) {
	actions[eventName].push(new EventAction(actionID, parameters));
}

void EventInterpreter::update(Event *e) {
	switch(actions[e->name()].back()->actionID()) {
		case 0:		action0(e);		break;
		case 1:		action1(e);		break;
		default:					break;
	};
}

void EventInterpreter::action0(Event *e) {
	ParameterList *params = actions[e->name()].back()->parameters();
	
	if(params->at(0)->isString() && !e->isLocked()) {
		ActivityManager::drawMessage(*(std::string*)(params->at(0)->value()));
		e->lock();
	}
	
	if(ActivityManager::top()->type() != Activity::Type::Message) {
		e->unlock();
	}
}

void EventInterpreter::action1(Event *e) {
	ParameterList *params = actions[e->name()].back()->parameters();
	
	if(params->at(0)->isInteger()) {
		ActivityManager::startBattle(*(int*)(params->at(0)->value()));
	}
}

