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
	
	m_itemsNb = m_inventory.nbItems() + m_inventory.nbArmors() + m_inventory.nbWeapons();
	
	CharacterManager::player->inventory()->add(&m_inventory);
	
	for(auto &it : m_battle->actors()) {
		it.second->gainExp(m_battle->exp() / m_battle->actors().size());
	}
	CharacterManager::player->gainGold(m_battle->gold());
	Sound::Effect::play(Sound::Effect::confirm);
}

VictoryWindow::~VictoryWindow() {
}

void VictoryWindow::draw() {
	m_height = 134 + 32 * m_itemsNb;
	
	m_y = 319 / 2 - m_height / 2; // GameWindow::main->height() - 319 = ActorStatsWindow->height()
	
	Window::draw();
	
	Interface::defaultFont->printCentered(_t("Victory").c_str(), m_x, m_y + 20, m_width, 21, FONT_LARGE);
	printStat(20, 52, _t("EXP"), m_battle->exp(), 60, 180);
	printStat(20, 84, _t("Gold"), m_battle->gold(), 60, 180);
	
	u16 i = 0;
	for(u16 j = 0 ; j < m_inventory.nbItems() ; j++) {
		printItem(m_inventory.getItem(j), 0, 20, 116 + i * 32, 160);
		i++;
	}
	for(u16 j = 0 ; j < m_inventory.nbArmors() ; j++) {
		printItem(m_inventory.getArmor(j), 0, 20, 116 + i * 32, 160);
		i++;
	}
	for(u16 j = 0 ; j < m_inventory.nbWeapons() ; j++) {
		printItem(m_inventory.getWeapon(j), 0, 20, 116 + i * 32, 160);
		i++;
	}
}

