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

void ActorStatsWindow::draw(std::vector<Enemy*> enemies, std::vector<Actor*> actors) {
	Window::draw();
	
	for(u8 i = 0 ; i < enemies.size() ; i++) {
		drawEnemy(enemies[i], i, enemies.size());
	}
	
	for(u8 i = 0 ; i < actors.size() ; i++) {
		drawActor(actors[i], i);
	}
}

void ActorStatsWindow::drawEnemy(Enemy *enemy, u8 pos, u8 max) {
	enemy->image()->render(m_width / 2 - enemy->image()->width() / 2 + pos * enemy->image()->width(), 320 / 2 - enemy->image()->width() + 10);
}

void ActorStatsWindow::drawActor(Actor *actor, u8 pos) {
	Image level, hpImg, spImg;
	
	actor->image()->setAlphaMod(190);
	actor->image()->render(m_width / 4 * (pos + 0.5) - actor->image()->width() / 2, m_y - 25);
	
	Interface::defaultFont->printScaled(actor->name().c_str(), m_x + GameWindow::main->viewportX() + 20 + m_width / 4 * pos, m_y + GameWindow::main->viewportY() + 20, m_width - 20, 32, FONT_LARGE);
	
	Interface::defaultFont->printScaled(_t("Lv").c_str(), m_x + GameWindow::main->viewportX() + 20 + m_width / 4 * pos, m_y + GameWindow::main->viewportY() + 52, 25, 32, FONT_LARGE, Color::system);
	Interface::defaultFont->printToImage(to_string(actor->level()).c_str(), m_x + GameWindow::main->viewportX() + m_width / 4 * (pos + 1) - 20, m_y + GameWindow::main->viewportY() + 52, &level, FONT_LARGE);
	level.render(level.posRect().x - level.width());
	
	Interface::defaultFont->printScaled(_t("HP").c_str(), m_x + GameWindow::main->viewportX() + 20 + m_width / 4 * pos, m_y + GameWindow::main->viewportY() + 84, 60, 32, FONT_LARGE, Color::system);
	Interface::defaultFont->printToImage(to_string(actor->hp()).c_str(), m_x + GameWindow::main->viewportX() + m_width / 4 * (pos + 1) - 20, m_y + GameWindow::main->viewportY() + 84, &hpImg, FONT_LARGE);
	
	Interface::defaultFont->printScaled(_t("SP").c_str(), m_x + GameWindow::main->viewportX() + 20 + m_width / 4 * pos, m_y + GameWindow::main->viewportY() + 116, 60, 32, FONT_LARGE, Color::system);
	Interface::defaultFont->printToImage(to_string(actor->sp()).c_str(), m_x + GameWindow::main->viewportX() + m_width / 4 * (pos + 1) - 20, m_y + GameWindow::main->viewportY() + 116, &spImg, FONT_LARGE);
	
	hpImg.render(hpImg.posRect().x - hpImg.width());
	spImg.render(spImg.posRect().x - spImg.width());
}

