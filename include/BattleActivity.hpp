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
#define BATTLEACTIVITY_HPP_

class BattleActivity : public Activity {
	public:
		BattleActivity();
		~BattleActivity();
		
		void update();
		void render();
		
		u8 mode() const { return (u8)m_mode; }
		
		enum Mode {
			Choice,
			Action,
			ChooseActorTarget,
			ChooseEnemyTarget,
			EnemyTurn,
			ProcessActions
		};
		
	private:
		Battle *m_battle;
		
		ActorStatsWindow m_actorStatswin;
		
		s8 m_currentPos;
		s8 m_arrowPos;
		
		u8 m_mode;
		
		BattleChoiceWindow m_battleChoicewin;
		BattleActionWindow m_battleActionwin;
		
		InfoWindow *m_infowin;
		
		Item *m_currentItem;
		
		bool m_processingAction;
};

#endif // BATTLEACTIVITY_HPP_
