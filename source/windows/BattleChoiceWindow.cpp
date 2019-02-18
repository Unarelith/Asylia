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
#include "Config.hpp"
#include "BattleChoiceWindow.hpp"

BattleChoiceWindow::BattleChoiceWindow() : CommandWindow(0, 0, SCREEN_WIDTH, true, true) {
	addCommand(_t("Fight"));
	addCommand(_t("Escape"));

	m_columnMax = 2;
}

