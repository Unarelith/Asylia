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
		BattleActivity(Troop *troop, bool allowDefeat = false);
		~BattleActivity();

		void update();
		void render();

		Battle *battle() { return m_battle; }

		s8 currentPos() const { return m_currentPos; }

		u8 mode() const { return (u8)m_mode; }

		enum Mode {
			Choice,
			Action,
			ItemWin,
			ChooseActorTarget,
			ChooseEnemyTarget,
			EnemyTurn,
			ProcessActions,
			GameOver,
			Victory,
		};

	private:
		Troop *m_troop;

		Battle *m_battle;

		ActorStatsWindow m_actorStatswin;

		s8 m_currentPos;
		s8 m_arrowPos;

		u8 m_mode;

		BattleChoiceWindow m_battleChoicewin;
		BattleActionWindow m_battleActionwin;

		ItemWindow *m_itemwin;

		InfoWindow *m_infowin;

		Item *m_currentItem;

		bool m_processingAction;

		Image *m_gameover;
		u16 m_gameoverAlpha;

		VictoryWindow *m_victorywin;

		bool m_allowDefeat;
};

#endif // BATTLEACTIVITY_HPP_
