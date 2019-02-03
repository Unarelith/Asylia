/*
 * =====================================================================================
 *
 *       Filename:  TextWindow.cpp
 *
 *    Description:
 *
 *        Created:  23/03/2014 18:22:52
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Interface.hpp"
#include "TextWindow.hpp"

TextWindow::TextWindow(s16 x, s16 y, u16 width, u16 height) : Window(x, y, width, height) {
}

void TextWindow::draw(const std::string &text) {
	Window::draw();

	Interface::defaultFont->printTextBox(text.c_str(), m_x + 22, m_y + 21, m_width - 44, m_height - 42, FONT_LARGE);
}

