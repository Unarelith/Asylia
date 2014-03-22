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

SelectableWindow::SelectableWindow(s16 x, s16 y, u16 width, u16 height) : Window(x, y, width, height) {
	m_itemMax = 1;
	m_columnMax = 1;
	
	m_pos = -1;
}

SelectableWindow::~SelectableWindow() {
}

void SelectableWindow::updateCursor() {
	u16 x, y;
	u16 row, cursorWidth;
	
	cursorWidth = m_width / m_columnMax - 32;
	x = m_pos % m_columnMax * (cursorWidth + 32);
	y = m_pos / m_columnMax * 32 - 0;
	
	m_cursor = Rectangle(x, y, cursorWidth, 32);
}

void SelectableWindow::update() {
	Window::update();
	
	if(Keyboard::isKeyPressedWithDelay(Keyboard::GameUp, 200)) {
		m_pos--;
		Sound::Effect::play(Sound::Effect::move);
	}
	
	if(Keyboard::isKeyPressedWithDelay(Keyboard::GameDown, 200)) {
		m_pos++;
		Sound::Effect::play(Sound::Effect::move);
	}
	
	if(Keyboard::isKeyPressedWithDelay(Keyboard::GameLeft, 200)) {
		
	}
	
	if(Keyboard::isKeyPressedWithDelay(Keyboard::GameRight, 200)) {
		
	}
	
	if(m_pos >= m_itemMax) {
		m_pos = 0;
	}
	
	if(m_pos < 0) {
		m_pos = m_itemMax - 1;
	}
	
	updateCursor();
}

