/*
 * =====================================================================================
 *
 *       Filename:  Window.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 00:33:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Window::Window(s16 x, s16 y, u16 width, u16 height) {
	m_x = x + GameWindow::main->viewportX();
	m_y = y + GameWindow::main->viewportY();
	
	m_width = width;
	m_height = height;
	
	m_cursor = Rectangle(0, 0, 0, 0);
}

Window::~Window() {
}

void Window::update() {
}

void Window::drawCursor(s16 x, s16 y, u16 width, u16 height) {
	Interface::interface->setAlpha(abs(int(SDL_GetTicks() / 4 % 255 - 128)) + 127);
	
	Interface::interface->render(x, y, width, height, 129, 64, 30, 32);
	
	Interface::interface->render(x, y, 1, height, 128, 64, 1, 32);
	Interface::interface->render(x + width - 1, y, 1, height, 159, 64, 1, 32);
	
	Interface::interface->setAlpha(255);
}

void Window::draw() {
	Interface::interface->setAlpha(225);
	Interface::interface->render(m_x + 3, m_y + 3, m_width - 6, m_height - 6, 0, 0, 128, 128);
	Interface::interface->setAlpha(255);
	
	Interface::interface->render(m_x, m_y, 3, 3, 128, 0, 3, 3);
	Interface::interface->render(m_x + m_width - 3, m_y, 3, 3, 189, 0, 3, 3);
	Interface::interface->render(m_x, m_y + m_height - 3, 3, 3, 128, 61, 3, 3);
	Interface::interface->render(m_x + m_width - 3, m_y + m_height - 3, 3, 3, 189, 61, 3, 3);
	
	Interface::interface->render(m_x + 3, m_y, m_width - 6, 3, 132, 0, 58, 3);
	Interface::interface->render(m_x, m_y + 3, 3, m_height - 6, 128, 3, 3, 58);
	Interface::interface->render(m_x + 3, m_y + m_height - 3, m_width - 6, 3, 132, 61, 58, 3);
	Interface::interface->render(m_x + m_width - 3, m_y + 3, 3, m_height - 6, 189, 3, 3, 58);
	
	if(m_cursor.width > 0) {
		drawCursor(16 + m_x + m_cursor.x, 16 + m_y + m_cursor.y, m_cursor.width, m_cursor.height);
	}
}

