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
	
	for(auto &it : m_battle->enemies()) {
		m_inventory.add(it.second->inventory());
	}
	
	m_itemsNb = 0;
	for(auto &it : m_battle->enemies()) {
		m_itemsNb += it.second->inventory()->nbItems();
		m_itemsNb += it.second->inventory()->nbArmors();
		m_itemsNb += it.second->inventory()->nbWeapons();
	}
}

VictoryWindow::~VictoryWindow() {
}

void VictoryWindow::draw() {
	m_height = 134 + 32 * itemsNb;
	
	m_y = 319 / 2 - m_height / 2; // GameWindow::main->height() - 319 = ActorStatsWindow->height()
	
	Window::draw();
	
	Interface::defaultFont->printCentered(_t("Victory").c_str(), m_x, m_y + 20, m_width, 21, FONT_LARGE);
	printStat(20, 52, _t("EXP"), m_battle->exp(), 60, 180);
	printStat(20, 84, _t("Gold"), m_battle->gold(), 60, 180);
	
	u16 i = 0;
	for(auto &it : m_battle->enemies()) {
		for(u16 j = 0 ; j < it.second->inventory()->nbItems() ; j++) {
			printItem(it.second->inventory()->getItem(j), 0, 20, 116 + i * 32, 160);
			i++;
		}
		for(u16 j = 0 ; j < it.second->inventory()->nbArmors() ; j++) {
			printItem(it.second->inventory()->getArmor(j), 0, 20, 116 + i * 32, 160);
			i++;
		}
		for(u16 j = 0 ; j < it.second->inventory()->nbWeapons() ; j++) {
			printItem(it.second->inventory()->getWeapon(j), 0, 20, 116 + i * 32, 160);
			i++;
		}
	}
}

