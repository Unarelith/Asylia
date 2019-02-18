/*
 * =====================================================================================
 *
 *       Filename:  BattleState.hpp
 *
 *    Description:
 *
 *        Created:  22/04/2014 19:18:46
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef BATTLESTATE_HPP_
#define BATTLESTATE_HPP_

#include <memory>

#include <gk/core/ApplicationState.hpp>

#include "ActorStatsWindow.hpp"
#include "Battle.hpp"
#include "BattleActionWindow.hpp"
#include "BattleChoiceWindow.hpp"
#include "GameWindow.hpp"
#include "ItemWindow.hpp"
#include "Troop.hpp"
#include "VictoryWindow.hpp"

class BattleState : public gk::ApplicationState {
	public:
		BattleState(Troop *troop, bool allowDefeat = false);

		void update();
		void render();

		Battle &battle() { return m_battle; }

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
		Troop *m_troop = nullptr;

		Battle m_battle;

		ActorStatsWindow m_actorStatswin;

		s8 m_currentPos;
		s8 m_arrowPos;

		u8 m_mode;

		BattleChoiceWindow m_battleChoicewin;
		BattleActionWindow m_battleActionwin;

		std::unique_ptr<ItemWindow> m_itemwin;

		InfoWindow m_infowin{0, 0, GameWindow::main->width(), 52};

		Item *m_currentItem;

		bool m_processingAction;

		Image m_gameover{"resources/graphics/interface/Gameover.jpg"};
		u16 m_gameoverAlpha;

		VictoryWindow m_victorywin;

		bool m_allowDefeat;
};

#endif // BATTLESTATE_HPP_
