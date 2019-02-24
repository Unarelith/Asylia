/*
 * =====================================================================================
 *
 *       Filename:  Troop.hpp
 *
 *    Description:
 *
 *        Created:  11/06/2014 15:30:01
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TROOP_HPP_
#define TROOP_HPP_

#include "Enemy.hpp"

class Troop {
	public:
		Troop(const std::string &battleback = "");

		gk::Image &battleback() { return m_battleback; }
		bool isBattlebackLoaded() { return m_isBattlebackLoaded; }

		void addEnemy(Enemy *enemy, s16 x, s16 y) { m_enemies.push_back(std::make_tuple(enemy, x, y)); }

		Enemy *getEnemy(u8 pos) { return std::get<0>(m_enemies[pos]); }
		s16 getEnemyX(u8 pos) { return std::get<1>(m_enemies[pos]); }
		s16 getEnemyY(u8 pos) { return std::get<2>(m_enemies[pos]); }

		u8 size() { return m_enemies.size(); }

	private:
		gk::Image m_battleback;
		bool m_isBattlebackLoaded = false;

		std::vector<std::tuple<Enemy*,s16,s16>> m_enemies;
};

#endif // TROOP_HPP_
