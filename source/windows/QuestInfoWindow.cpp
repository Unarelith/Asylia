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

QuestInfoWindow::QuestInfoWindow() : Window(200, 114, GameWindow::main->width() - 200, GameWindow::main->height() - 114) {
}

QuestInfoWindow::~QuestInfoWindow() {
}

void QuestInfoWindow::draw(Quest *quest) {
	Window::draw();
	
	if(quest) {
		std::string questName = _t(std::string("Quest") + to_string(quest->id()));
		std::string questDesc = std::string("    ") + _t(std::string("Quest") + to_string(quest->id()) + "Desc");
		
		Interface::defaultFont->printCentered(questName.c_str(), m_x, m_y, GameWindow::main->width() - m_x, 64, FONT_MAXI);
		
		Interface::defaultFont->print((_t("Description") + ":").c_str(), m_x + 20, m_y + 66, FONT_LARGE, Color::system);
		
		Interface::defaultFont->printTextBox(questDesc.c_str(), m_x + 30, m_y + 98, m_width - 60, 64, FONT_LARGE);
		
		Interface::defaultFont->print((_t("Objectives") + ":").c_str(), m_x + 20, m_y + 182, FONT_LARGE, Color::system);
		
		for(auto it : quest->objectives()) {
			std::string objectiveDesc = std::string("- ") + _t(std::string("Quest") + to_string(quest->id()) + "_Obj" + to_string(it->id()) + "Desc");
			
			Interface::defaultFont->print(objectiveDesc.c_str(), m_x + 30, m_y + 214 + 32 * it->id(), FONT_LARGE);
		}
	}
}

