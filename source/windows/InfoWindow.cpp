/*
 * =====================================================================================
 *
 *       Filename:  InfoWindow.cpp
 *
 *    Description:
 *
 *        Created:  05/04/2014 15:57:15
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "InfoWindow.hpp"
#include "ResourceHelper.hpp"

InfoWindow::InfoWindow(s16 x, s16 y, u16 width, u16 height) : Window(x, y, width, height) {
}

void InfoWindow::drawTextScaled(std::string text) {
	Window::draw();

	// FIXME
	// ResourceHelper::getFont("default").printScaled(text.c_str(), m_x + 18, m_y + 15, m_width - 16, 32, FONT_LARGE);
}

void InfoWindow::drawTextCentered(std::string text) {
	Window::draw();

	// FIXME
	// ResourceHelper::getFont("default").printCentered(text.c_str(), m_x, m_y, m_width, m_height, FONT_LARGE);
}

