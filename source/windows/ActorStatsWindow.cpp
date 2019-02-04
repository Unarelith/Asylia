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
#include "ActorStatsWindow.hpp"
#include "BattleState.hpp"
#include "GameWindow.hpp"
#include "ApplicationStateStack.hpp"

ActorStatsWindow::ActorStatsWindow() : Window(0, 319, GameWindow::main->width(), GameWindow::main->height() - 319) {
}

void ActorStatsWindow::drawActors(const std::vector<std::pair<u8, Actor*>> &actors) {
	Window::draw();

	for(u8 i = 0 ; i < actors.size() ; i++) {
		drawActor(actors[i].second, i);
	}
}

void ActorStatsWindow::drawActor(Actor *actor, u8 pos) {
	BattleState &battleState = ((BattleState&)ApplicationStateStack::getInstance().top());
	u8 mode = battleState.mode();
	if((mode == BattleState::Mode::Choice || mode == BattleState::Mode::EnemyTurn || mode == BattleState::Mode::ProcessActions || mode == BattleState::Mode::Victory)
	|| (battleState.battle().actors()[battleState.currentPos()].second != actor)) {
		actor->image()->setColorMod(Color::white);
		actor->image()->setAlphaMod(190);
	}

	drawBattler(actor, m_width / 4 * (pos + 0.5) - actor->image()->width() / 2, GameWindow::main->height() - actor->image()->height());

	printName(actor, 20 + m_width / 4 * pos, 20, m_width - 40);
	printState(actor, 20 + m_width / 4 * pos, 116, m_width - 40);
	printHP(actor, 20 + m_width / 4 * pos, 52, m_width / 4 * (pos + 1) - 20);
	printSP(actor, 20 + m_width / 4 * pos, 84, m_width / 4 * (pos + 1) - 20);
}

void ActorStatsWindow::drawEnemies(const std::vector<std::pair<u8, Enemy*>> &enemies) {
	for(u8 i = 0 ; i < enemies.size() ; i++) {
		drawEnemy(enemies[i].second, i, enemies.size());
	}
}

void ActorStatsWindow::drawEnemy(Enemy *enemy, u8 pos, u8 max) {
	drawBattler(enemy, enemy->image()->posRect().x, enemy->image()->posRect().y);
}

