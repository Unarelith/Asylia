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
	Image hpImg, spImg;
	
	if(((BattleActivity*)ActivityManager::top())->mode() % 4 == 0) {
		actor->image()->setAlphaMod(190);
	}
	
	actor->image()->render(GameWindow::main->viewportX() + m_width / 4 * (pos + 0.5) - actor->image()->width() / 2, GameWindow::main->viewportY() + m_y - actor->image()->height() / 6);
	
	Interface::defaultFont->printScaled(actor->name().c_str(), m_x + GameWindow::main->viewportX() + 20 + m_width / 4 * pos, m_y + GameWindow::main->viewportY() + 20, m_width - 40, 32, FONT_LARGE);
	
	Interface::defaultFont->printScaled(_t("HP").c_str(), m_x + GameWindow::main->viewportX() + 20 + m_width / 4 * pos, m_y + GameWindow::main->viewportY() + 52, 60, 32, FONT_LARGE, Color::system);
	Interface::defaultFont->printToImage(to_string(actor->hp()).c_str(), m_x + GameWindow::main->viewportX() + m_width / 4 * (pos + 1) - 20, m_y + GameWindow::main->viewportY() + 52, &hpImg, FONT_LARGE);
	
	Interface::defaultFont->printScaled(_t("SP").c_str(), m_x + GameWindow::main->viewportX() + 20 + m_width / 4 * pos, m_y + GameWindow::main->viewportY() + 84, 60, 32, FONT_LARGE, Color::system);
	Interface::defaultFont->printToImage(to_string(actor->sp()).c_str(), m_x + GameWindow::main->viewportX() + m_width / 4 * (pos + 1) - 20, m_y + GameWindow::main->viewportY() + 84, &spImg, FONT_LARGE);
	
	hpImg.render(hpImg.posRect().x - hpImg.width());
	spImg.render(spImg.posRect().x - spImg.width());
	
	Interface::defaultFont->printScaled(actor->getStateString().c_str(), m_x + GameWindow::main->viewportX() + 20 + m_width / 4 * pos, m_y + GameWindow::main->viewportY() + 116, m_width - 40, 32, FONT_LARGE);
}

void ActorStatsWindow::drawEnemies(std::vector<std::pair<u8, Enemy*>> enemies) {
	for(u8 i = 0 ; i < enemies.size() ; i++) {
		drawEnemy(enemies[i].second, i, enemies.size());
	}
}

void ActorStatsWindow::drawEnemy(Enemy *enemy, u8 pos, u8 max) {
	enemy->image()->render();
}

