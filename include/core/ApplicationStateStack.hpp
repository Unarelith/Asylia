/*
 * =====================================================================================
 *
 *       Filename:  ApplicationStateStack.hpp
 *
 *    Description:
 *
 *        Created:  20/03/2014 21:15:19
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef APPLICATIONSTATESTACK_HPP_
#define APPLICATIONSTATESTACK_HPP_

#include <stack>

#include "ApplicationState.hpp"
#include "BattleState.hpp"
#include "MessageState.hpp"
#include "Singleton.hpp"
#include "TroopManager.hpp"

class ApplicationStateStack : public Singleton<ApplicationStateStack> {
	public:
		template<typename T, typename... Args>
		auto push(Args &&...args) -> typename std::enable_if<std::is_base_of<ApplicationState, T>::value, T&>::type {
			m_states.emplace(std::make_shared<T>(std::forward<Args>(args)...));
			// m_states.top()->setStateStack(this);
			if(top().parent()) top().screenshot(top().parent()); // FIXME
			return static_cast<T&>(top());
		}

		void pop() { m_states.pop(); }
		ApplicationState &top() const { return *m_states.top().get(); }
		bool empty() const { return m_states.empty(); }
		std::size_t size() const { return m_states.size(); }

		// FIXME: To remove
		static MessageState *drawMessage(const std::string &message) {
			getInstance().top().render();
			return &getInstance().push<MessageState>(message);
		}

		// FIXME: To remove
		static BattleState *startBattle(u16 id, bool allowDefeat) {
			return &getInstance().push<BattleState>(TroopManager::getInstance().getTroop(id), allowDefeat);
		}

	private:
		std::stack<std::shared_ptr<ApplicationState>> m_states;
};

#endif // APPLICATIONSTATESTACK_HPP_
