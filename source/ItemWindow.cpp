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
	
	m_pos = 0;
}

ItemWindow::~ItemWindow() {
}

void ItemWindow::addItem(std::string item) {
	m_items.push_back(item);
	m_itemMax++;
}

void ItemWindow::drawItem(u8 pos) {
	u16 x, y, width, height;
	
	x = 4 + pos % 2 * (288 + 32);
	y = pos / 2 * 32;
	
	width = m_width / m_columnMax - 32;
	height = 32;
	
	Interface::defaultFont->printScaled(m_items[pos].c_str(), m_x + GameWindow::main->viewportX() + x, m_y + GameWindow::main->viewportY() + y, width, height, FONT_LARGE, Color::white);
}

void ItemWindow::draw() {
	SelectableWindow::draw();
	
	for(u8 i = 0 ; i < m_itemMax ; i++) {
		drawItem(i);
	}
}

