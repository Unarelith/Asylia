/*
 * =====================================================================================
 *
 *       Filename:  BattleActivity.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/04/2014 19:18:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef BATTLEACTIVITY_HPP_
#define BATTLEACTIVITY_HPP

class BattleActivity : public Activity {
	public:
		BattleActivity();
		~BattleActivity();
		
		void addEnemy(Enemy *enemy) { m_enemies.push_back(enemy); }
		void addActor(Actor *actor) { m_actors.push_back(actor); }
		
		void update();
		void render();
		
	private:
		std::vector<Enemy*> m_enemies;
		std::vector<Actor*> m_actors;
		
		std::vector<ActorStatsWindow*> m_actorsStatswin;
		
		Actor *m_currentActor;
		
		Image *m_battleback;
};

#endif // BATTLEACTIVITY_HPP_
