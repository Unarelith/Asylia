/*
 * =====================================================================================
 *
 *       Filename:  BattleChoiceWindow.cpp
 *
 *    Description:
 *
 *        Created:  23/04/2014 18:58:30
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

BattleChoiceWindow::BattleChoiceWindow() : CommandWindow(0, 0, GameWindow::main->width(), true, true) {
	addCommand(_t("Fight"));
	addCommand(_t("Escape"));

	m_columnMax = 2;
}

BattleChoiceWindow::~BattleChoiceWindow() {
}

