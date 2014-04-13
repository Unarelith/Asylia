/*
 * =====================================================================================
 *
 *       Filename:  EquipStatsWindow.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/04/2014 17:29:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

EquipStatsWindow::EquipStatsWindow() : Window(150, 52, (GameWindow::main->width() - 150) / 2, (GameWindow::main->height() - 52) / 2) {
}

EquipStatsWindow::~EquipStatsWindow() {
}

void EquipStatsWindow::draw() {
	Window::draw();
	
	Interface::defaultFont->printScaled(CharacterManager::player->name().c_str(), m_x + GameWindow::main->viewportX() + 20, m_y + GameWindow::main->viewportY() + 20, m_width - 130, 32, FONT_LARGE);
	Interface::defaultFont->printScaled(_t("Lv").c_str(), m_x + GameWindow::main->viewportX() + m_width - 90, m_y + GameWindow::main->viewportY() + 20, 25, 32, FONT_LARGE, Color::system);
	Image *level = Interface::defaultFont->printToImage(to_string(CharacterManager::player->level()).c_str(), m_x + GameWindow::main->viewportX() + m_width - 20, m_y + GameWindow::main->viewportY() + 20, FONT_LARGE);
	
	level->render(level->posRect().x - level->width());
	
	delete level;
}

