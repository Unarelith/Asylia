/*
 * =====================================================================================
 *
 *       Filename:  InfoWindow.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2014 15:57:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

InfoWindow::InfoWindow(s16 x, s16 y, u16 width, u16 height) : Window(x, y, width, height) {
}

InfoWindow::~InfoWindow() {
}

void InfoWindow::drawTextCentered(std::string text) {
	Window::draw();
	
	Interface::defaultFont->printCentered(text.c_str(), m_x + GameWindow::main->viewportX(), m_y + GameWindow::main->viewportY(), m_width, m_height, FONT_LARGE);
}

