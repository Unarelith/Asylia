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
		
		void update();
		void render();
		
		enum Mode {
			Choice,
			Action,
			EnemyTurn
		};
		
	private:
		Battle *m_battle;
		
		ActorStatsWindow m_actorStatswin;
		
		Actor *m_currentActor;
		u8 m_currentPos;
		
		Mode m_mode;
		
		BattleChoiceWindow m_battleChoicewin;
		BattleActionWindow m_battleActionwin;
};

#endif // BATTLEACTIVITY_HPP_
