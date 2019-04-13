/*
 * =====================================================================================
 *
 *       Filename:  Window.cpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 00:33:17
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/SDLHeaders.hpp>

#include "Color.hpp"
#include "ResourceHelper.hpp"
#include "Window.hpp"

Window::Window(s16 x, s16 y, u16 width, u16 height) {
	setPosition(x, y);

	m_width = width;
	m_height = height;

	m_cursorRect = gk::IntRect(0, 0, 0, 0);
}

void Window::printStat(s16 x, s16 y, const std::string &statName, s32 statValue, u16 nameWidth, u16 x2, u16 max, gk::RenderTarget &target, gk::RenderStates states) const {
	// Image statImg;
    //
	// ResourceHelper::getFont("default").printScaled(statName.c_str(), m_x + x, m_y + y, nameWidth, 28, FONT_LARGE, Color::System);
    //
	// if(max == 0) ResourceHelper::getFont("default").printToImage(
	// std::to_string(statValue).c_str(), m_x + x2, m_y + y, &statImg, FONT_LARGE);
	// else ResourceHelper::getFont("default").printToImage(
	// std::string(std::to_string(statValue) + "/" + std::to_string(max)).c_str(),
	// m_x + x2, m_y + y, &statImg, FONT_LARGE);
    //
	// statImg.render(statImg.posRect().x - statImg.width());

	m_text.setString(statName);
	m_text.setColor(Color::System);
	m_text.setScaled(true);
	m_text.setSize({nameWidth, 28});
	m_text.setPosition(x, y);
	target.draw(m_text, states);

	if (max == 0)
		m_text.setString(std::to_string(statValue));
	else
		m_text.setString(std::to_string(statValue) + "/" + std::to_string(max));
	m_text.setColor(gk::Color::White);
	m_text.setScaled(false);
	m_text.setPosition(x2 - m_text.getLocalBounds().width, y);
	target.draw(m_text, states);
}

void Window::printName(Battler *battler, s16 x, s16 y, u16 width, gk::RenderTarget &target, gk::RenderStates states) const {
	// ResourceHelper::getFont("default").printScaled(battler->name().c_str(), m_x + x, m_y + y, width, 28, FONT_LARGE);

	m_text.setString(battler->name());
	m_text.setColor(Color::System);
	m_text.setScaled(true);
	m_text.setSize({width, 28});
	m_text.setPosition(x, y);
	target.draw(m_text, states);
}

void Window::printState(Battler *battler, s16 x, s16 y, u16 width, gk::RenderTarget &target, gk::RenderStates states) const {
	// ResourceHelper::getFont("default").printScaled(battler->getStateString().c_str(), m_x + x, m_y + y, width, 28, FONT_LARGE);

	m_text.setString(battler->getStateString());
	m_text.setColor(Color::System);
	m_text.setScaled(true);
	m_text.setSize({width, 28});
	m_text.setPosition(x, y);
	target.draw(m_text, states);
}

void Window::printLevel(Battler *battler, s16 x, s16 y, s16 x2, gk::RenderTarget &target, gk::RenderStates states) const {
	printStat(x, y, _t("Lv"), battler->level(), 25, x2, 0, target, states);
}

void Window::printHP(Battler *battler, s16 x, s16 y, s16 x2, bool onMaximum, gk::RenderTarget &target, gk::RenderStates states) const {
	printStat(x, y, _t("HP"), battler->hp(), 60, x2, (onMaximum)?(battler->basehp()):(0), target, states);
}

void Window::printSP(Battler *battler, s16 x, s16 y, s16 x2, bool onMaximum, gk::RenderTarget &target, gk::RenderStates states) const {
	printStat(x, y, _t("SP"), battler->sp(), 60, x2, (onMaximum)?(battler->basesp()):(0), target, states);
}

void Window::printExp(Battler *battler, s16 x, s16 y, s16 x2, bool onMaximum, gk::RenderTarget &target, gk::RenderStates states) const {
	printStat(x, y, _t("EXP"), battler->exp(), 60, x2, (onMaximum)?(battler->exp() + battler->expRemainingToLevelUp()):(0), target, states);
}

void Window::drawBattler(Battler *battler, s16 x, s16 y, gk::RenderTarget &target, gk::RenderStates states) const {
	battler->image().setPosition(x, y);
	target.draw(battler->image(), states);
}

void Window::printItem(Item *item, u16 count, s16 x, s16 y, u16 width, gk::RenderTarget &target, gk::RenderStates states) const {
	// gk::Image countImg, itemImg;
    //
	// item->thumbnail().render(m_x + x, m_y + y);
    //
	// if(count != 0) {
	// 	ResourceHelper::getFont("default").printToImage(std::to_string(count).c_str(), m_x + x - 16 + width, m_y + y, &countImg, FONT_LARGE);
	// 	countImg.render(countImg.posRect().x - countImg.width());
	// }
    //
	// ResourceHelper::getFont("default").printScaledToImage(item->name().c_str(), m_x + x + 28, m_y + y, width - countImg.width(), 32, &itemImg, FONT_LARGE);
    //
	// if(m_y + y < m_y) {
	// 	itemImg.render(-1, m_y + 4, 0, itemImg.height() - (y + 32 - m_y), -1, m_y - y + 4, 0, itemImg.height() - (y + 32 - m_y));
	// }
	// else if(m_y + y + 32 > m_y + m_height) {
	// 	itemImg.render(-1, m_y + y, 0, m_height - y - 4, -1, -1, 0, m_height - y - 4);
	// } else {
	// 	itemImg.render(-1, -1, 0, 0, -1, -1, 0, 0);
	// }

	// TODO
}

void Window::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	states.transform *= getTransform();

	drawWindow(0, 0, m_width, m_height, target, states);

	if (m_isCursorVisible)
		drawCursor(16 + m_cursorRect.x, 16 + m_cursorRect.y, m_cursorRect.width, m_cursorRect.height, target, states);
}

void Window::drawWindow(int x, int y, u16 width, u16 height, gk::RenderTarget &target, gk::RenderStates states) const {
	m_window.setAlphaMod(225);
	drawImagePart({x + 1, y + 1, width - 2, height - 2}, {0, 0, 128, 128}, target, states);
	m_window.setAlphaMod(255);

	drawImagePart({x, y, 3, 3}, {128, 0, 3, 3}, target, states);
	drawImagePart({x + width - 3, y, 3, 3}, {189, 0, 3, 3}, target, states);
	drawImagePart({x, y + height - 3, 3, 3}, {128, 61, 3, 3}, target, states);
	drawImagePart({x + width - 3, y + height - 3, 3, 3}, {189, 61, 3, 3}, target, states);

	drawImagePart({x + 3, y, width - 6, 3}, {132, 0, 58, 3}, target, states);
	drawImagePart({x, y + 3, 3, height - 6}, {128, 3, 3, 58}, target, states);
	drawImagePart({x + 3, y + height - 3, width - 6, 3}, {132, 61, 58, 3}, target, states);
	drawImagePart({x + width - 3, y + 3, 3, height - 6}, {189, 3, 3, 58}, target, states);
}

void Window::drawCursor(int x, int y, u16 width, u16 height, gk::RenderTarget &target, gk::RenderStates states) const {
	m_window.setAlphaMod(abs(int(SDL_GetTicks() / 4 % 255 - 128)) + 127);

	drawImagePart({x, y, width, height}, {132, 68, 23, 23}, target, states);

	drawImagePart({x, y, 1, height}, {128, 64, 1, 32}, target, states);
	drawImagePart({x + width - 1, y, 1, height}, {159, 64, 1, 32}, target, states);

	drawImagePart({x, y, width, 1}, {129, 64, 31, 1}, target, states);
	drawImagePart({x, y + height - 1, width, 1}, {129, 95, 31, 1}, target, states);

	m_window.setAlphaMod(255);
}

void Window::drawImagePart(const gk::IntRect &posRect, const gk::IntRect &clipRect, gk::RenderTarget &target, gk::RenderStates states) const {
	m_window.setClipRect(clipRect.x, clipRect.y, clipRect.width, clipRect.height);
	m_window.setPosRect(posRect.x, posRect.y, posRect.width, posRect.height);
	target.draw(m_window, states);
}

