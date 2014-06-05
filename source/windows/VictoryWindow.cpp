/*
 * =====================================================================================
 *
 *       Filename:  VictoryWindow.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  31/05/2014 16:20:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

VictoryWindow::VictoryWindow(Battle *battle) : Window(GameWindow::main->width() / 2 - 100, 0, 200, 150) {
	m_battle = battle;
}

VictoryWindow::~VictoryWindow() {
}

void VictoryWindow::draw() {
	u16 itemsNb = 2;
	
	m_height = 134 + 32 * itemsNb;
	
	m_y = 319 / 2 - m_height / 2; // GameWindow::main->height() - 319 = ActorStatsWindow->height()
	
	Window::draw();
	
	Interface::defaultFont->printCentered(_t("Victory").c_str(), m_x, m_y + 20, m_width, 21, FONT_LARGE);
	printStat(20, 52, _t("EXP"), m_battle->exp(), 60, 180);
	printStat(20, 84, _t("Gold"), m_battle->gold(), 60, 180);
	
	printItem(ItemManager::items[0], 0, 20, 116, 160);
	printItem(ItemManager::items[1], 0, 20, 148, 160);
}

