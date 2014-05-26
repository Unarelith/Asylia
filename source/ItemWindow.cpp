/*
 * =====================================================================================
 *
 *       Filename:  ItemWindow.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  24/03/2014 22:15:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

ItemWindow::ItemWindow(s16 x, s16 y, u16 width, u16 height) : SelectableWindow(x, y + 52, width, height) {
	m_itemMax = CharacterManager::player->inventory()->nbItems();
	m_columnMax = 2;
	
	m_pos = 0;
	
	m_infoWindow = new InfoWindow(x, y, width, 52);
}

ItemWindow::~ItemWindow() {
}

void ItemWindow::drawItem(u8 pos) {
	s16 x, y, width, height;
	Image count, image;
	
	width = m_width / m_columnMax - 32;
	height = 32;
	
	x = 22 + pos % m_columnMax * (width + 32);
	y = 21 + pos / m_columnMax * 32 - m_scroll * 32;
	
	CharacterManager::player->inventory()->getItem(pos)->thumbnail()->render(m_x + x, m_y + y);
	
	Interface::defaultFont->printToImage(to_string(CharacterManager::player->inventory()->getItemCount(pos)).c_str(), m_x + x - 16 + width, m_y + y, &count, FONT_LARGE);
	count.render(count.posRect().x - count.width());
	
	Interface::defaultFont->printScaledToImage(CharacterManager::player->inventory()->getItem(pos)->name().c_str(), m_x + x + 28, m_y + y, width - count.width(), height, &image, FONT_LARGE);
	
	if(m_y + y < m_y) {
		image.render(-1, m_y + 4, 0, image.height() - (y + 32 - m_y), -1, m_y - y + 4, 0, image.height() - (y + 32 - m_y));
	}
	else if(m_y + y + height > m_y + m_height) {
		image.render(-1, m_y + y, 0, m_height - y - 4, -1, -1, 0, m_height - y - 4);
	} else {
		image.render(-1, -1, 0, 0, -1, -1, 0, 0);
	}
}

void ItemWindow::draw() {
	SelectableWindow::draw();
	
	m_infoWindow->drawTextScaled(CharacterManager::player->inventory()->getItem(m_pos)->description());
	
	for(u8 i = 0 ; i < m_itemMax ; i++) {
		drawItem(i);
	}
}

