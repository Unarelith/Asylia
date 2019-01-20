/*
 * =====================================================================================
 *
 *       Filename:  BattlerManager.hpp
 *
 *    Description:
 *
 *        Created:  27/04/2014 20:44:27
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef BATTLERMANAGER_HPP_
#define BATTLERMANAGER_HPP_

namespace BattlerManager {
	void init();
	void free();

	void initActors();
	void initEnemies();

	extern std::vector<Actor*> actors;
	extern std::vector<Enemy*> enemies;
};

#endif // BATTLERMANAGER_HPP_
