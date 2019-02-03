/*
 * =====================================================================================
 *
 *       Filename:  Quest.hpp
 *
 *    Description:
 *
 *        Created:  29/06/2014 19:58:44
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef QUEST_HPP_
#define QUEST_HPP_

#include "Inventory.hpp"
#include "QuestObjective.hpp"

class Quest {
	public:
		Quest(u16 exp, u16 gold);
		~Quest();

		void addObjective(QuestObjective *objective) { m_objectives.push_back(objective); m_objectives.back()->setID(m_objectives.size() - 1); }

		u16 id() const { return m_id; }

		u16 exp() const { return m_exp; }
		u16 gold() const { return m_gold; }
		Inventory *items() { return &m_items; }

		bool completed() const { return m_completed; }

		std::vector<QuestObjective*> objectives() const { return m_objectives; }

		static u16 counter;

	private:
		u16 m_id;

		u16 m_exp;
		u16 m_gold;
		Inventory m_items;

		bool m_completed;

		std::vector<QuestObjective*> m_objectives;
};

#endif // QUEST_HPP_
