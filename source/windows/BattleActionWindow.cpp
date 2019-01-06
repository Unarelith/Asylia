/*
 * =====================================================================================
 *
 *       Filename:  BattleActionWindow.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  23/04/2014 18:57:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

BattleActionWindow::BattleActionWindow() : CommandWindow(0, 159, GameWindow::main->width() / 4) {
	addCommand("Attack");
	addCommand("Skill", true);
	addCommand("Defend", true);
	addCommand("Item");
}

BattleActionWindow::~BattleActionWindow() {
}

void BattleActionWindow::draw(u8 pos) {
	m_x = pos * GameWindow::main->width() / 4;

	CommandWindow::draw();
}

