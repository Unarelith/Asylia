/*
 * =====================================================================================
 *
 *       Filename:  ActorStatsWindow.cpp
 *
 *    Description:
 *
 *        Created:  13/04/2014 17:29:09
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/ApplicationStateStack.hpp>

#include "ActorStatsWindow.hpp"
#include "BattleState.hpp"
#include "Config.hpp"

ActorStatsWindow::ActorStatsWindow() : Window(0, 319, SCREEN_WIDTH, SCREEN_HEIGHT - 319) {
}

void ActorStatsWindow::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	Window::draw(target, states);

	if (m_battle) {
		for (auto &it : m_battle->actors())
			drawActor(it.second, it.first, target, states);

		for (auto &it : m_battle->enemies())
			drawEnemy(it.second, target, states);
	}
}

void ActorStatsWindow::drawActor(Actor *actor, u8 pos, gk::RenderTarget &target, gk::RenderStates states) const {
	BattleState &battleState = ((BattleState&)gk::ApplicationStateStack::getInstance().top());
	u8 mode = battleState.mode();
	if((mode == BattleState::Mode::Choice || mode == BattleState::Mode::EnemyTurn || mode == BattleState::Mode::ProcessActions || mode == BattleState::Mode::Victory)
	|| (battleState.battle().actors()[battleState.currentPos()].second != actor)) {
		actor->image().setColor(gk::Color::White);
		actor->image().setAlphaMod(190);
	}

	drawBattler(actor, m_width / 4 * (pos + 0.5) - actor->image().width() / 2, SCREEN_HEIGHT - actor->image().height(), target, states);

	states.transform *= getTransform();

	printName(actor, 20 + m_width / 4 * pos, 20, m_width - 40, target, states);
	printState(actor, 20 + m_width / 4 * pos, 116, m_width - 40, target, states);
	printHP(actor, 20 + m_width / 4 * pos, 52, m_width / 4 * (pos + 1) - 20, false, target, states);
	printSP(actor, 20 + m_width / 4 * pos, 84, m_width / 4 * (pos + 1) - 20, false, target, states);
}

void ActorStatsWindow::drawEnemy(Enemy *enemy, gk::RenderTarget &target, gk::RenderStates states) const {
	drawBattler(enemy, enemy->image().posRect().x, enemy->image().posRect().y, target, states);
}

