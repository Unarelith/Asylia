/*
 * =====================================================================================
 *
 *       Filename:  Troop.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/06/2014 15:30:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef TROOP_HPP_
#define TROOP_HPP_

class Troop {
	public:
		Troop();
		~Troop();
		
		void addEnemy(Enemy *enemy, s16 x, s16 y) { m_enemies.push_back(enemy); }
		
		Enemy *getEnemy(u8 pos) { return std::get<0>(m_enemies); }
		s16 getEnemyX(u8 pos) { return std::get<1>(m_enemies); }
		s16 getEnemyY(u8 pos) { return std::get<2>(m_enemies); }
		
		u8 size() { return m_enemies.size(); }
		
	private:
		std::vector<std::tuple<Enemy*,s16,s16>> m_enemies;
}

#endif // TROOP_HPP_
