/*
 * =====================================================================================
 *
 *       Filename:  StateManager.hpp
 *
 *    Description:
 *
 *        Created:  20/03/2014 21:15:19
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef STATEMANAGER_HPP_
#define STATEMANAGER_HPP_

#include <stack>

#include "ApplicationState.hpp"
#include "BattleState.hpp"
#include "MessageState.hpp"
#include "TroopManager.hpp"

class StateManager {
	public:
		static void init();
		static void free();

		static std::stack<ApplicationState*> activities;

		static ApplicationState *top() { return activities.top(); }
		static void pop() { delete top(); activities.pop(); }
		static void push(ApplicationState *state);
		static int size() { return activities.size(); }

		static MessageState *drawMessage(const std::string &message) {
			top()->render();
			MessageState *state = new MessageState(message);
			push(state);
			return state;
		}

		static BattleState *startBattle(u16 id, bool allowDefeat) {
			BattleState *state = new BattleState(TroopManager::troops[id], allowDefeat);
			push(state);
			return state;
		}
};

#endif // STATEMANAGER_HPP_
