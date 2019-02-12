/*
 * =====================================================================================
 *
 *       Filename:  QuestManager.hpp
 *
 *    Description:
 *
 *        Created:  30/06/2014 16:25:45
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef QUESTMANAGER_HPP_
#define QUESTMANAGER_HPP_

#include <memory>

#include "Quest.hpp"

class QuestManager : public Singleton<QuestManager> {
	public:
		void init();

		Quest *getQuest(size_t i) { return m_quests[i].get(); }

	private:
		std::vector<std::unique_ptr<Quest>> m_quests;
};

#endif // QUESTMANAGER_HPP_
