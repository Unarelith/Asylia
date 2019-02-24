/*
 * =====================================================================================
 *
 *       Filename:  CommandWindow.cpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 13:15:22
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Color.hpp"
#include "CommandWindow.hpp"
#include "ResourceHelper.hpp"

CommandWindow::CommandWindow(s16 x, s16 y, u16 width, bool horizontal, bool centered) : SelectableWindow(x, y, width, (horizontal)?(64):(32)) {
	m_horizontal = horizontal;
	m_centered = centered;

	m_itemMax = 0;

	m_pos = 0;
}

CommandWindow::CommandWindow(u16 width) : SelectableWindow(0, 0, width, 32) {
	m_horizontal = false;
	m_centered = false;

	m_itemMax = 0;

	m_pos = 0;
}

// void CommandWindow::drawItem(u8 pos) {
// 	ResourceHelper::getFont("default").printScaled(_t(m_commands[pos].first).c_str(), m_x + 22, m_y + 22 + 32 * pos, m_width - 40 - 5, 32, FONT_LARGE, (!m_commands[pos].second)?(gk::Color::White):(Color::Disabled));
// }
//
// void CommandWindow::drawHorizontalCenteredItem(u8 pos) {
// 	u16 x, y, width;
//
// 	width = m_width / m_columnMax - 32;
// 	x = pos % m_columnMax * (width + 32) + 16;
// 	y = pos / m_columnMax * 32 + 16;
//
// 	ResourceHelper::getFont("default").printCentered(_t(m_commands[pos].first).c_str(), m_x + x, m_y + y, width, 32, FONT_LARGE, (!m_commands[pos].second)?(gk::Color::White):(Color::Disabled));
// }
//
// void CommandWindow::draw(bool cursor) {
// 	SelectableWindow::draw(cursor);
//
// 	for(u8 i = 0 ; i < m_itemMax ; i++) {
// 		if(!m_horizontal && !m_centered) {
// 			drawItem(i);
// 		} else {
// 			drawHorizontalCenteredItem(i);
// 		}
// 	}
// }

void CommandWindow::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	Window::draw(target, states);

	states.transform *= getTransform();

	// FIXME
	int i = 0;
	for (auto &it : m_commands) {
		if (!m_horizontal && !m_centered) {
			gk::Text t{_t(it.text().text()), "font-default", 18};
			t.setPosition(it.text().getPosition());
			t.setColor(it.isEnabled() ? gk::Color::White : Color::Disabled);
			target.draw(t, states);
		}
		else {
			u16 x, y, width;

			width = m_width / m_columnMax - 32;
			x = (i % m_columnMax) * (width + 32) + 16;
			y = (i / m_columnMax) * 32 + 16;

			gk::Text t{_t(it.text().text()), "font-default", 18};
			t.setPosition(it.text().getPosition().x + x, it.text().getPosition().y + y);
			t.setColor(it.isEnabled() ? gk::Color::White : Color::Disabled);
			target.draw(t, states);
		}

		++i;

		// target.draw(it.text(), states);
	}
}

