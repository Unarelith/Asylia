/*
 * =====================================================================================
 *
 *       Filename:  EquipEquipItemWindow.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/04/2014 16:15:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */

#include "Asylia.hpp"

EquipItemWindow::EquipItemWindow(u8 equipment, u8 equipType) : SelectableWindow(150, 52 + (GameWindow::main->height() - 52) / 2, GameWindow::main->width() - 150, (GameWindow::main->height() - 52) / 2) {
	m_itemMax = 0;
	m_columnMax = 2;
	
	m_pos = 0;
	
	m_infoWindow = new InfoWindow(150, 0, GameWindow::main->width() - 150, 52);
	
	if(equipment == 0) {
		for(auto& it : CharacterManager::player->inventory()->weapons()) {
			if(it.first->equipType() == equipType && it.first != CharacterManager::player->inventory()->weapon()) {
				m_inventory.pushBackItem((Item*)it.first, it.second);
			}
		}
	} else {
		for(auto& it : CharacterManager::player->inventory()->armors()) {
			if(it.first->slot() == equipType && it.first != CharacterManager::player->inventory()->armor(it.first->slot())) {
				m_inventory.pushBackItem((Item*)it.first, it.second);
			}
		}
	}
	
	m_itemMax = m_inventory.nbItems();
}

EquipItemWindow::~EquipItemWindow() {
}

void EquipItemWindow::drawItem(u8 pos) {
	s16 x, y, width, height;
	Image count, image;
	
	width = m_width / m_columnMax - 32;
	height = 32;
	
	x = 20 + pos % m_columnMax * (width + 32);
	y = 20 + pos / m_columnMax * 32 - m_scroll * 32;
	
	m_inventory.getItem(pos)->thumbnail()->render(m_x + GameWindow::main->viewportX() + x, m_y + GameWindow::main->viewportY() + y);
	
	Interface::defaultFont->printToImage(to_string(m_inventory.getItemCount(pos)).c_str(), m_x + GameWindow::main->viewportX() + x - 16 + width, m_y + GameWindow::main->viewportY() + y, &count, FONT_LARGE);
	count.render(count.posRect().x - count.width());
	
	Interface::defaultFont->printScaledToImage(m_inventory.getItem(pos)->name().c_str(), m_x + GameWindow::main->viewportX() + x + 28, m_y + GameWindow::main->viewportY() + y, width - count.width(), height, &image, FONT_LARGE);
	
	if(m_y + y < m_y) {
		image.render(-1, GameWindow::main->viewportY() + m_y + 4, 0, image.height() - (y + 32 - m_y), -1, m_y - y + 4, 0, image.height() - (y + 32 - m_y));
	}
	else if(m_y + y + height > m_y + m_height) {
		image.render(-1, GameWindow::main->viewportY() + m_y + y, 0, m_height - y - 4, -1, -1, 0, m_height - y - 4);
	} else {
		image.render(-1, -1, 0, 0, -1, -1, 0, 0);
	}
}

void EquipItemWindow::draw(bool drawInfoWindow, bool drawCursor) {
	SelectableWindow::draw(drawCursor);
	
	if(drawInfoWindow) m_infoWindow->drawTextScaled(m_inventory.getItem(m_pos)->description());
	else m_infoWindow->drawTextScaled(" ");
	
	for(u8 i = 0 ; i < m_itemMax ; i++) {
		drawItem(i);
	}
}

void EquipItemWindow::changeSet(u8 equipment, u8 equipType) {
	m_inventory.clear();
	
	if(equipment == 0) {
		for(auto& it : CharacterManager::player->inventory()->weapons()) {
			if(it.first->equipType() == equipType && it.first != CharacterManager::player->inventory()->weapon()) {
				m_inventory.pushBackItem((Item*)it.first, it.second);
			}
		}
	} else {
		for(auto& it : CharacterManager::player->inventory()->armors()) {
			if(it.first->slot() == equipType && it.first != CharacterManager::player->inventory()->armor(it.first->slot())) {
				m_inventory.pushBackItem((Item*)it.first, it.second);
			}
		}
	}
	
	m_itemMax = m_inventory.nbItems();
}

Item *EquipItemWindow::currentItem() {
	return m_inventory.getItem(m_pos);
}

