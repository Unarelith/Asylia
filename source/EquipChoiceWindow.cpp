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
		ItemManager::weapons[0]->thumbnail()->render(m_x + 20, m_y + 20);
		Interface::defaultFont->setStyle(FONT_LARGE, TTF_STYLE_ITALIC);
		Interface::defaultFont->printScaled(_t("Empty").c_str(), m_x + 48, m_y + 20, m_width - 40, 32, FONT_LARGE, Color::system);
		Interface::defaultFont->setStyle(FONT_LARGE, TTF_STYLE_NORMAL);
	} else {
		CharacterManager::player->inventory()->weapon()->thumbnail()->render(m_x + 20, m_y + 20);
		Interface::defaultFont->printScaled(CharacterManager::player->inventory()->weapon()->name().c_str(), m_x + 48, m_y + 20, m_width - 40, 32, FONT_LARGE);
	}
	
	for(u8 slot = 0 ; slot < 3 ; slot++) {
		Armor *armor = CharacterManager::player->inventory()->armor(slot);
		if(!armor) {
			for(auto it : ItemManager::armors) {
				if(it->slot() == slot) {
					it->thumbnail()->render(m_x + 20, m_y + 52 + slot * 32);
					break;
				}
			}
			Interface::defaultFont->setStyle(FONT_LARGE, TTF_STYLE_ITALIC);
			Interface::defaultFont->printScaled(_t("Empty").c_str(), m_x + 48, m_y + 52 + slot * 32, m_width - 40, 32, FONT_LARGE, Color::system);
			Interface::defaultFont->setStyle(FONT_LARGE, TTF_STYLE_NORMAL);
		} else {
			armor->thumbnail()->render(m_x + 20, m_y + 52 + slot * 32);
			Interface::defaultFont->printScaled(armor->name().c_str(), m_x + 48, m_y + 52 + slot * 32, m_width - 40, 32, FONT_LARGE);
		}
	}
}

