/*
 * =====================================================================================
 *
 *       Filename:  QuestInfoWindow.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  30/06/2014 18:52:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

QuestInfoWindow::QuestInfoWindow() : Window(200, 116, GameWindow::main->width() - 200, GameWindow::main->height() - 116) {
	m_mode = Mode::ObjectivesMode;
}

QuestInfoWindow::~QuestInfoWindow() {
}

void QuestInfoWindow::update() {
	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		if(m_mode == Mode::ObjectivesMode) m_mode = Mode::RewardsMode;
		else if(m_mode == Mode::RewardsMode) m_mode = Mode::ObjectivesMode;
	}
}

void QuestInfoWindow::draw(Quest *quest) {
	drawWindow(m_x, m_y, m_width, 64);
	drawWindow(m_x, m_y + 64, m_width, 134);
	
	if(m_mode == Mode::ObjectivesMode) {
		drawWindow(m_x, m_y + 198, m_width, m_height - 198);
	}
	else if(m_mode == Mode::RewardsMode) {
		drawWindow(m_x, m_y + 198, m_width / 2, m_height - 198);
		drawWindow(m_x + m_width / 2, m_y + 198, m_width / 2, m_height - 198);
	}
	
	if(quest) {
		std::string questName = _t(std::string("Quest") + to_string(quest->id()));
		std::string questDesc = std::string("    ") + _t(std::string("Quest") + to_string(quest->id()) + "Desc");
		
		Interface::defaultFont->printCentered(questName.c_str(), m_x, m_y, GameWindow::main->width() - m_x, 64, FONT_MAXI);
		
		Interface::defaultFont->print((_t("Description") + ":").c_str(), m_x + 20, m_y + 80, FONT_LARGE, Color::system);
		
		Interface::defaultFont->printTextBox(questDesc.c_str(), m_x + 30, m_y + 110, m_width - 60, 64, FONT_LARGE);
		
		if(m_mode == Mode::ObjectivesMode) {
			Interface::defaultFont->print((_t("Objectives") + ":").c_str(), m_x + 20, m_y + 214, FONT_LARGE, Color::system);
			
			for(auto it : quest->objectives()) {
				std::string objectiveDesc = std::string("- ") + _t(std::string("Quest") + to_string(quest->id()) + "_Obj" + to_string(it->id()) + "Desc");
				
				Interface::defaultFont->print(objectiveDesc.c_str(), m_x + 30, m_y + 242 + 28 * it->id(), FONT_LARGE);
			}
		}
		else if(m_mode == Mode::RewardsMode) {
			Interface::defaultFont->print((_t("Rewards") + ":").c_str(), m_x + 20, m_y + 214, FONT_LARGE, Color::system);
			
			printStat(30, 260, _t("EXP"), quest->exp(), 60, m_width / 2 - 40);
			printStat(30, 292, _t("Gold"), quest->gold(), 60, m_width / 2 - 40);
			
			Interface::defaultFont->print((_t("Items") + ":").c_str(), m_x + m_width / 2 + 20, m_y + 214, FONT_LARGE, Color::system);
			
			u16 j = 0;
			for(u16 i = 0 ; i < quest->items()->nbItems() ; i++) {
				printItem(quest->items()->getItem(i), quest->items()->getItemCount(i), m_width / 2 + 30, 242 + j * 28, m_width / 2 - 50);
				j++;
			}
			for(u16 i = 0 ; i < quest->items()->nbArmors() ; i++) {
				printItem(quest->items()->getArmor(i), quest->items()->getArmorCount(i), m_width / 2 + 30, 242 + j * 28, m_width / 2 - 50);
				j++;
			}
			for(u16 i = 0 ; i < quest->items()->nbWeapons() ; i++) {
				printItem(quest->items()->getWeapon(i), quest->items()->getWeaponCount(i), m_width / 2 + 30, 242 + j * 28, m_width / 2 - 50);
				j++;
			}
		}
	}
}

