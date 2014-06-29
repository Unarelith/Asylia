/*
 * =====================================================================================
 *
 *       Filename:  Quest.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29/06/2014 19:58:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef QUEST_HPP_
#define QUEST_HPP_

class Quest {
	public:
		Quest(u16 exp, u16 gold);
		~Quest();
		
		void addObjective(QuestObjective *objective) { m_objectives.push_back(objective); }
		
		Inventory *items() { return &m_items; }
		
	private:
		u16 m_exp;
		u16 m_gold;
		Inventory m_items;
		
		std::vector<QuestObjective*> m_objectives;
};

#endif // QUEST_HPP_
