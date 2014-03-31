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

ItemWindow::ItemWindow() : SelectableWindow(150, 0, 490, 480) {
	m_itemMax = 0;
	m_columnMax = 3;
	
	m_pos = 0;
}

ItemWindow::~ItemWindow() {
}

void ItemWindow::addItem(std::string item) {
	m_items.push_back(item);
	m_itemMax++;
}

void ItemWindow::drawItem(u8 pos) {
	s16 x, y, width, height;
	
	width = m_width / m_columnMax - 32;
	height = 32;
	
	x = 20 + pos % m_columnMax * (width + 32);
	y = 20 + pos / m_columnMax * 32 - m_scroll * 32;
	
	Image *image = Interface::defaultFont->printScaledToImage(m_items[pos].c_str(), m_x + GameWindow::main->viewportX() + x, m_y + GameWindow::main->viewportY() + y, width, height, FONT_LARGE, Color::white);
	
	//if(pos == 0) debug("Scroll: %d: %d | %d", m_scroll, m_y, y);
	// Scroll 0: 0 | 20
	// Scroll 1: 0 | -12
	
	if(pos == 0) debug("Scroll %d: %d, %d", m_scroll, y + 32 - m_y, image->height() - (y + 32 - m_y));
	// Scroll 0: 52, -27
	// Scroll 1: 20, 5
	
	// Image height = 25
	
	if(y < m_y) {
		image->render(-1, m_y + 4, 0, image->height() - (y + 32 - m_y), -1, m_y - y, 0, image->height() - (y + 32 - m_y));
	} else {
		image->render(-1, -1, 0, 0, -1, -1, 0, 0);
	}
	
	//image->render(-1, -1, 0, 0, -1, -1, 0, 0);
	
	delete image;
}

void ItemWindow::draw() {
	SelectableWindow::draw();
	
	for(u8 i = 0 ; i < m_itemMax ; i++) {
		drawItem(i);
	}
}

