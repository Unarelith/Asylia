/*
 * =====================================================================================
 *
 *       Filename:  Battle.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  23/04/2014 18:03:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef BATTLE_HPP_
#define BATTLE_HPP_

class Battle {
	public:
		Battle(std::string battleback);
		~Battle();
		
		void addActor(Actor *actor) { m_actors.push_back(actor); }
		void addEnemy(Enemy *enemy) { m_enemies.push_back(enemy); }
		
		std::vector<Actor*> actors() const { return m_actors; }
		std::vector<Enemy*> enemies() const { return m_enemies; }
		
		void renderBattleback() { m_battleback->render(); }
		
	private:
		std::vector<Actor*> m_actors;
		std::vector<Enemy*> m_enemies;
		
		Image *m_battleback;
};

#endif // BATTLE_HPP_
