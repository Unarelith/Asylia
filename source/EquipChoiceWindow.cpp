/*
 * =====================================================================================
 *
 *       Filename:  EquipChoiceWindow.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  17/04/2014 20:45:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

EquipChoiceWindow::EquipChoiceWindow() : SelectableWindow(150 + (GameWindow::main->width() - 150) / 2, 52, (GameWindow::main->width() - 150) / 2, (GameWindow::main->height() - 52) / 2) {
	m_itemMax = 4;
	m_columnMax = 1;
	
	m_pos = 0;
}

EquipChoiceWindow::~EquipChoiceWindow() {
}

void EquipChoiceWindow::draw(bool drawCursor) {
	SelectableWindow::draw(drawCursor);
	
	if(!CharacterManager::player->inventory()->weapon()) {
		ItemManager::weapons[0]->thumbnail()->render(m_x + GameWindow::main->viewportX() + 20, m_y + GameWindow::main->viewportY() + 20);
		Interface::defaultFont->setStyle(FONT_LARGE, TTF_STYLE_ITALIC);
		Interface::defaultFont->printScaled(_t("Empty").c_str(), m_x + GameWindow::main->viewportX() + 48, m_y + GameWindow::main->viewportY() + 20, m_width - 40, 32, FONT_LARGE, Color::system);
		Interface::defaultFont->setStyle(FONT_LARGE, TTF_STYLE_NORMAL);
	} else {
		CharacterManager::player->inventory()->weapon()->thumbnail()->render(m_x + GameWindow::main->viewportX() + 20, m_y + GameWindow::main->viewportY() + 20);
		Interface::defaultFont->printScaled(CharacterManager::player->inventory()->weapon()->name().c_str(), m_x + GameWindow::main->viewportX() + 48, m_y + GameWindow::main->viewportY() + 20, m_width - 40, 32, FONT_LARGE);
	}
	
	if(!CharacterManager::player->inventory()->shield()) {
		ItemManager::armors[0]->thumbnail()->render(m_x + GameWindow::main->viewportX() + 20, m_y + GameWindow::main->viewportY() + 52);
		Interface::defaultFont->setStyle(FONT_LARGE, TTF_STYLE_ITALIC);
		Interface::defaultFont->printScaled(_t("Empty").c_str(), m_x + GameWindow::main->viewportX() + 48, m_y + GameWindow::main->viewportY() + 52, m_width - 40, 32, FONT_LARGE, Color::system);
		Interface::defaultFont->setStyle(FONT_LARGE, TTF_STYLE_NORMAL);
	} else {
		CharacterManager::player->inventory()->shield()->thumbnail()->render(m_x + GameWindow::main->viewportX() + 20, m_y + GameWindow::main->viewportY() + 52);
		Interface::defaultFont->printScaled(CharacterManager::player->inventory()->shield()->name().c_str(), m_x + GameWindow::main->viewportX() + 48, m_y + GameWindow::main->viewportY() + 52, m_width - 40, 32, FONT_LARGE);
	}
	
	if(!CharacterManager::player->inventory()->helmet()) {
		ItemManager::armors[1]->thumbnail()->render(m_x + GameWindow::main->viewportX() + 20, m_y + GameWindow::main->viewportY() + 84);
		Interface::defaultFont->setStyle(FONT_LARGE, TTF_STYLE_ITALIC);
		Interface::defaultFont->printScaled(_t("Empty").c_str(), m_x + GameWindow::main->viewportX() + 48, m_y + GameWindow::main->viewportY() + 84, m_width - 40, 32, FONT_LARGE, Color::system);
		Interface::defaultFont->setStyle(FONT_LARGE, TTF_STYLE_NORMAL);
	} else {
		CharacterManager::player->inventory()->helmet()->thumbnail()->render(m_x + GameWindow::main->viewportX() + 20, m_y + GameWindow::main->viewportY() + 84);
		Interface::defaultFont->printScaled(CharacterManager::player->inventory()->helmet()->name().c_str(), m_x + GameWindow::main->viewportX() + 48, m_y + GameWindow::main->viewportY() + 84, m_width - 40, 32, FONT_LARGE);
	}
	
	if(!CharacterManager::player->inventory()->armor()) {
		ItemManager::armors[3]->thumbnail()->render(m_x + GameWindow::main->viewportX() + 20, m_y + GameWindow::main->viewportY() + 116);
		Interface::defaultFont->setStyle(FONT_LARGE, TTF_STYLE_ITALIC);
		Interface::defaultFont->printScaled(_t("Empty").c_str(), m_x + GameWindow::main->viewportX() + 48, m_y + GameWindow::main->viewportY() + 116, m_width - 40, 32, FONT_LARGE, Color::system);
		Interface::defaultFont->setStyle(FONT_LARGE, TTF_STYLE_NORMAL);
	} else {
		CharacterManager::player->inventory()->armor()->thumbnail()->render(m_x + GameWindow::main->viewportX() + 20, m_y + GameWindow::main->viewportY() + 116);
		Interface::defaultFont->printScaled(CharacterManager::player->inventory()->armor()->name().c_str(), m_x + GameWindow::main->viewportX() + 48, m_y + GameWindow::main->viewportY() + 116, m_width - 40, 32, FONT_LARGE);
	}
}

