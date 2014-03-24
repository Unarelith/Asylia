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
	
	m_scroll = 0;
}

SelectableWindow::~SelectableWindow() {
}

void SelectableWindow::updateCursor() {
	u16 x, y, cursorWidth;
	
	cursorWidth = m_width / m_columnMax - 32;
	x = m_pos % m_columnMax * (cursorWidth + 32);
	y = m_pos / m_columnMax * 32 - 0;
	
	m_cursor = Rectangle(x, y, cursorWidth, 32);
}

void SelectableWindow::update() {
	Window::update();
	
	u8 rowMax = m_width / 32 - 1;
	
	if(Keyboard::isKeyPressedWithDelay(Keyboard::GameUp, 150)) {
		if(m_pos - m_columnMax >= 0) m_pos -= m_columnMax;
		else if(m_columnMax == 1) m_pos = m_itemMax - 1;
		if(m_pos / m_columnMax < m_scroll) m_scroll--; 
		Sound::Effect::play(Sound::Effect::move);
	}
	
	if(Keyboard::isKeyPressedWithDelay(Keyboard::GameDown, 150)) {
		if(m_pos + m_columnMax < m_itemMax) m_pos += m_columnMax;
		else if(m_columnMax == 1) m_pos = 0;
		if(m_pos / m_columnMax > rowMax + m_scroll) m_scroll++; 
		Sound::Effect::play(Sound::Effect::move);
	}
	
	if(Keyboard::isKeyPressedWithDelay(Keyboard::GameLeft, 150)) {
		if(m_pos > 0 && m_columnMax > 1) m_pos--;
		if(m_pos / m_columnMax < m_scroll) m_scroll--; 
		Sound::Effect::play(Sound::Effect::move);
	}
	
	if(Keyboard::isKeyPressedWithDelay(Keyboard::GameRight, 100)) {
		if(m_pos < m_itemMax && m_columnMax > 1) m_pos++;
		if(m_pos / m_columnMax > rowMax + m_scroll) m_scroll++; 
		Sound::Effect::play(Sound::Effect::move);
	}
	
	updateCursor();
}

