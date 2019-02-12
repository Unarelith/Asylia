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

#include <memory>

#include "Actor.hpp"
#include "Enemy.hpp"

class BattlerManager : public Singleton<BattlerManager> {
	public:
		void init();

		void initActors();
		void initEnemies();

		Actor *getActor(size_t i) { return m_actors[i].get(); }
		Enemy *getEnemy(size_t i) { return m_enemies[i].get(); }

	private:
		std::vector<std::unique_ptr<Actor>> m_actors;
		std::vector<std::unique_ptr<Enemy>> m_enemies;
};

#endif // BATTLERMANAGER_HPP_
