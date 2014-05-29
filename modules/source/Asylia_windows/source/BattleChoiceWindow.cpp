/*
 * =====================================================================================
 *
 *       Filename:  BattleChoiceWindow.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  23/04/2014 18:58:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

BattleChoiceWindow::BattleChoiceWindow() : CommandWindow(0, 0, GameWindow::main->width(), 64, true, true) {
	addCommand(_t("Fight"));
	addCommand(_t("Escape"));
	
	m_columnMax = 2;
}

BattleChoiceWindow::~BattleChoiceWindow() {
}

