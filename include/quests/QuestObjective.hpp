/*
 * =====================================================================================
 *
 *       Filename:  QuestObjective.hpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  29/06/2014 23:08:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef QUESTOBJECTIVE_HPP_
#define QUESTOBJECTIVE_HPP_

class QuestObjective {
	public:
		QuestObjective();
		QuestObjective(u16 itemToBring, Item::Type type, std::string eventToBringTo);
		QuestObjective(u16 itemToGet, Item::Type type, u16 count);
		QuestObjective(u16 enemyToBeat, u16 count);
		QuestObjective(std::string eventToTalkTo);
		~QuestObjective();

		enum Type {
			Undefined,

			BringItem,
			GetItem,

			BeatEnemy,

			TalkToSomeone
		};

		void setID(u16 id) { m_id = id; }
		u16 id() const { return m_id; }

	protected:
		Type m_type;

		u16 m_id;

		ParameterList m_params;
};

#endif // QUESTOBJECTIVE_HPP_
