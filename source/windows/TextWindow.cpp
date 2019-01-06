/*
 * =====================================================================================
 *
 *       Filename:  TextWindow.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  23/03/2014 18:22:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

TextWindow::TextWindow(s16 x, s16 y, u16 width, u16 height) : Window(x, y, width, height) {
}

TextWindow::~TextWindow() {
}

void TextWindow::draw(std::string text) {
	Window::draw();

	Interface::defaultFont->printTextBox(text.c_str(), m_x + 22, m_y + 21, m_width - 44, m_height - 42, FONT_LARGE);
}

