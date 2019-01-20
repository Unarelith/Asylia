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

namespace QuestManager {
	void init();
	void free();

	extern std::vector<Quest*> quests;
};

#endif // QUESTMANAGER_HPP_
