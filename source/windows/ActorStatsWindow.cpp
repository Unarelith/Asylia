/*
 * =====================================================================================
 *
 *       Filename:  ActorStatsWindow.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/04/2014 17:29:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

ActorStatsWindow::ActorStatsWindow() : Window(0, 319, GameWindow::main->width(), GameWindow::main->height() - 319) {
}

ActorStatsWindow::~ActorStatsWindow() {
}

void ActorStatsWindow::drawActors(std::vector<std::pair<u8, Actor*>> actors) {
	Window::draw();
	
	for(u8 i = 0 ; i < actors.size() ; i++) {
		drawActor(actors[i].second, i);
	}
}

void ActorStatsWindow::drawActor(Actor *actor, u8 pos) {
	BattleActivity *battleActivity = ((BattleActivity*)ActivityManager::top());
	u8 mode = battleActivity->mode();
	if((mode == BattleActivity::Mode::Choice || mode == BattleActivity::Mode::EnemyTurn || mode == BattleActivity::Mode::ProcessActions || mode == BattleActivity::Mode::Victory)
	|| (battleActivity->battle()->actors()[battleActivity->currentPos()].second != actor)) {
		actor->image()->setColorMod(Color::white);
		actor->image()->setAlphaMod(190);
	}
	
	drawBattler(actor, m_width / 4 * (pos + 0.5) - actor->image()->width() / 2, GameWindow::main->height() - actor->image()->height());
	
	printName(actor, 20 + m_width / 4 * pos, 20, m_width - 40);
	printHP(actor, 20 + m_width / 4 * pos, 52, m_width / 4 * (pos + 1) - 20);
	printSP(actor, 20 + m_width / 4 * pos, 84, m_width / 4 * (pos + 1) - 20);
	printState(actor, 20 + m_width / 4 * pos, 116, m_width - 40);
}

void ActorStatsWindow::drawEnemies(std::vector<std::pair<u8, Enemy*>> enemies) {
	for(u8 i = 0 ; i < enemies.size() ; i++) {
		drawEnemy(enemies[i].second, i, enemies.size());
	}
}

void ActorStatsWindow::drawEnemy(Enemy *enemy, u8 pos, u8 max) {
	drawBattler(enemy, enemy->image()->posRect().x, enemy->image()->posRect().y);
}

