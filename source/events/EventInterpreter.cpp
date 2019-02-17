/*
 * =====================================================================================
 *
 *       Filename:  EventInterpreter.cpp
 *
 *    Description:
 *
 *        Created:  17/06/2014 21:12:45
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/ApplicationStateStack.hpp>

#include "BattleState.hpp"
#include "EventInterpreter.hpp"
#include "EventListener.hpp"
#include "MessageState.hpp"
#include "ResourceHelper.hpp"

std::map<std::string, std::vector<EventAction*>> EventInterpreter::actions;

void EventInterpreter::free() {
	for(auto &it : actions) {
		while(it.second.size() != 0) {
			delete it.second.back();
			it.second.pop_back();
		}
	}
	actions.clear();
}

void EventInterpreter::addActionToQueue(u16 id, std::string eventName, u16 actionType, ParameterList parameters) {
	actions[eventName].push_back(new EventAction(id, actionType, parameters));
}

void EventInterpreter::update(Event *e) {
	if(actions[e->name()].size() == 0 || e->currentActionID() == -1) {
		e->currentActionID(0);
		while(actions[e->name()].size() != 0) {
			delete actions[e->name()].back();
			actions[e->name()].pop_back();
		}
		return;
	}

	switch(actions[e->name()][e->currentActionID()]->actionType()) {
		case 0:		action0(e);		break;
		case 1:		action1(e);		break;
		case 2:		action2(e);		break;
		default:					break;
	};
}

ParameterList *EventInterpreter::getParameters(Event *e) {
	return actions[e->name()][e->currentActionID()]->parameters();
}

/* Action 0: DrawText */
void EventInterpreter::action0(Event *e) {
	ParameterList *params = getParameters(e);

	if(params->at(0)->isString() && !e->isLocked()) {
		gk::ApplicationStateStack::getInstance().push<MessageState>(*(std::string*)(params->at(0)->value()));
		e->lock();
	}
	else {
		if(params->size() == 2 && params->at(1)->isInteger()) {
			e->currentActionID(*(int*)params->at(1)->value());
		}

		e->unlock();
		update(e);
	}
}

/* Action 1: StartBattle */
void EventInterpreter::action1(Event *e) {
	ParameterList *params = getParameters(e);

	if(params->at(0)->isInteger() && !e->isLocked() && params->at(1)->isBoolean()) {
		Troop *troop = ResourceHelper::getTroop(*(int*)(params->at(0)->value()));
		gk::ApplicationStateStack::getInstance().push<BattleState>(troop, *(bool*)(params->at(1)->value()));

		e->lock();
	}
	else {
		e->currentActionID(*(int*)params->at(2 + EventListener::lastBattleResult())->value());

		e->unlock();
	}
}

/* Action 2: AskQuestion */
void EventInterpreter::action2(Event *e) {
	ParameterList *params = getParameters(e);

	if(params->at(0)->isString() && !e->isLocked()) {
		MessageState &state = gk::ApplicationStateStack::getInstance().push<MessageState>(*(std::string*)(params->at(0)->value()));

		for(u16 i = 1 ; i < params->size() ; i+=2) {
			if(params->at(i)->isString()) {
				state.addCommand(*(std::string*)params->at(i)->value());
			}
		}

		e->lock();
	}
	else {
		if(params->at((SelectableWindow::lastPos + 1) * 2)->isInteger()) {
			e->currentActionID(*(int*)params->at((SelectableWindow::lastPos + 1) * 2)->value());
		}

		e->unlock();
		update(e);
	}
}

