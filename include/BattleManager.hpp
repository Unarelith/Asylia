/*
 * =====================================================================================
 *
 *       Filename:  BattleManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27/04/2014 21:09:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef BATTLEMANAGER_HPP_
#define BATTLEMANAGER_HPP_

namespace BattleManager {
	void init();
	void free();
	
	extern std::vector<Battle*> battles;
};

#endif // BATTLEMANGER_HPP_
