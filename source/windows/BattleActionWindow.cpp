/*
 * =====================================================================================
 *
 *       Filename:  BattleActionWindow.cpp
 *
 *    Description:
 *
 *        Created:  23/04/2014 18:57:38
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "BattleActionWindow.hpp"
#include "Config.hpp"

BattleActionWindow::BattleActionWindow() : CommandWindow(0, 159, SCREEN_WIDTH / 4) {
	addCommand("Attack");
	addCommand("Skill", true);
	addCommand("Defend", true);
	addCommand("Item");
}

void BattleActionWindow::setPos(u8 pos) {
	setX(pos * SCREEN_WIDTH / 4);
}

