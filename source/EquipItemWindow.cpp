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
			if(it.first->equipType() == equipType) {
				m_inventory.pushBackItem((Item*)it.first, it.second);
			}
		}
	} else {
		for(auto& it : CharacterManager::player->inventory()->armors()) {
			if(it.first->slot() == equipType) {
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
	
	width = m_width / m_columnMax - 32;
	height = 32;
	
	x = 20 + pos % m_columnMax * (width + 32);
	y = 20 + pos / m_columnMax * 32 - m_scroll * 32;
	
	m_inventory.getItem(pos)->thumbnail()->render(m_x + GameWindow::main->viewportX() + x, m_y + GameWindow::main->viewportY() + y);
	
	Image *count = Interface::defaultFont->printToImage(to_string(m_inventory.getItemCount(pos)).c_str(), m_x + GameWindow::main->viewportX() + x - 16 + width, m_y + GameWindow::main->viewportY() + y, FONT_LARGE);
	
	count->render(count->posRect().x - count->width());
	
	Image *image = Interface::defaultFont->printScaledToImage(m_inventory.getItem(pos)->name().c_str(), m_x + GameWindow::main->viewportX() + x + 28, m_y + GameWindow::main->viewportY() + y, width - count->width(), height, FONT_LARGE);
	
	if(m_y + y < m_y) {
		image->render(-1, GameWindow::main->viewportY() + m_y + 4, 0, image->height() - (y + 32 - m_y), -1, m_y - y + 4, 0, image->height() - (y + 32 - m_y));
	}
	else if(m_y + y + height > m_y + m_height) {
		image->render(-1, GameWindow::main->viewportY() + m_y + y, 0, m_height - y - 4, -1, -1, 0, m_height - y - 4);
	} else {
		image->render(-1, -1, 0, 0, -1, -1, 0, 0);
	}
	
	delete image;
	delete count;
}

void EquipItemWindow::draw() {
	SelectableWindow::draw();
	
	m_infoWindow->drawTextScaled(m_inventory.getItem(m_pos)->description());
	
	for(u8 i = 0 ; i < m_itemMax ; i++) {
		drawItem(i);
	}
}

