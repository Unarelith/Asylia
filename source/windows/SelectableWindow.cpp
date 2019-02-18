/*
 * =====================================================================================
 *
 *       Filename:  SelectableWindow.cpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 00:48:20
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/audio/AudioPlayer.hpp>
#include <gk/core/input/GamePad.hpp>

#include "GameKey.hpp"
#include "SelectableWindow.hpp"

u16 SelectableWindow::lastPos = 0;

SelectableWindow::SelectableWindow(s16 x, s16 y, u16 width, u16 height) : Window(x, y, width, height) {
	m_itemMax = 1;
	m_columnMax = 1;

	m_pos = -1;

	m_scroll = 0;
}

void SelectableWindow::updateCursor() {
	u16 x, y, cursorWidth;

	cursorWidth = m_width / m_columnMax - 32;
	x = m_pos % m_columnMax * (cursorWidth + 32);
	y = m_pos / m_columnMax * 32 - m_scroll * 32;

	m_cursor = gk::IntRect(x, y, cursorWidth, 32);

	lastPos = m_pos;
}

void SelectableWindow::update() {
	u8 rowMax = m_height / 32 - 1;

	if(gk::GamePad::isKeyPressedWithDelay(GameKey::Up, 150)) {
		if(m_pos - m_columnMax >= 0) {
			m_pos -= m_columnMax;
			gk::AudioPlayer::playSound("sound-move");
		}
		else if(m_columnMax == 1) {
			m_pos = m_itemMax - 1;
			gk::AudioPlayer::playSound("sound-move");
		}
		if(m_pos / m_columnMax < m_scroll) m_scroll--;
	}

	if(gk::GamePad::isKeyPressedWithDelay(GameKey::Down, 150)) {
		if(m_pos + m_columnMax < m_itemMax) {
			m_pos += m_columnMax;
			gk::AudioPlayer::playSound("sound-move");
		}
		else if(m_columnMax == 1) {
			m_pos = 0;
			gk::AudioPlayer::playSound("sound-move");
		}
		if(m_pos / m_columnMax >= rowMax + m_scroll) m_scroll++;
	}

	if(gk::GamePad::isKeyPressedWithDelay(GameKey::Left, 150)) {
		if(m_pos > 0 && m_columnMax > 1) {
			m_pos--;
			gk::AudioPlayer::playSound("sound-move");
		}
		if(m_pos / m_columnMax < m_scroll) m_scroll--;
	}

	if(gk::GamePad::isKeyPressedWithDelay(GameKey::Right, 150)) {
		if(m_pos < m_itemMax - 1 && m_columnMax > 1) {
			m_pos++;
			gk::AudioPlayer::playSound("sound-move");
		}
		if(m_pos / m_columnMax >= rowMax + m_scroll) m_scroll++;
	}

	updateCursor();
}

