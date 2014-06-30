/*
 * =====================================================================================
 *
 *       Filename:  QuestManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  30/06/2014 16:25:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
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
