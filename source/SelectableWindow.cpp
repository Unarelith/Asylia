/*
 * =====================================================================================
 *
 *       Filename:  SelectableWindow.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 00:48:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

SelectableWindow::SelectableWindow(s16 x, s16 y, u16 width, u16 height, std::string *choices) : Window(x, y, width, height) {
	m_choices = choices;
	
	m_rowMax = 1;
	m_columnMax = 1;
}

SelectableWindow::~SelectableWindow() {
}

void SelectableWindow::drawSelectionMarker(u16 width, u16 posX, u16 posY) {
	
}

void SelectableWindow::draw() {
	s16 offx, offy;
	
	offx = GameWindow::main->viewportW();
	offy = GameWindow::main->viewportH();
	
	Window::draw();
	
	for(u8 y = 0 ; y < m_rowMax ; y++) {
		for(u8 x = 0 ; x < m_columnMax ; x++) {
			Interface::defaultFont->print(m_choices[x + y * m_rowMax].c_str(), m_x + offx + 20, m_y + offy + 22 + 32 * y, FONT_LARGE, Color::white);
		}
	}
}

