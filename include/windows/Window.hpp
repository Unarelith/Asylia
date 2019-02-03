/*
 * =====================================================================================
 *
 *       Filename:  Window.hpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 00:30:53
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "Battler.hpp"
#include "Rectangle.hpp"

class Window {
	public:
		Window(s16 x, s16 y, u16 width, u16 height);
		~Window();

		void update();

		void drawCursor(s16 x, s16 y, u16 width, u16 height);
		void drawWindow(s16 x, s16 y, u16 width, u16 height);
		void draw(bool cursor = true);

		s16 x() const { return m_x; }
		s16 y() const { return m_y; }

		u16 width() const { return m_width; }
		u16 height() const { return m_height; }

		void x(s16 x) { m_x = x; }
		void y(s16 y) { m_y = y; }

		void width(u16 width) { m_width = width; }
		void height(u16 height) { m_height = height; }

		void printStat(s16 x, s16 y, std::string statName, s32 statValue, u16 nameWidth, u16 width, u16 max = 0);
		void printName(Battler *battler, s16 x, s16 y, u16 width);
		void printState(Battler *battler, s16 x, s16 y, u16 width);
		void printLevel(Battler *battler, s16 x, s16 y, s16 x2);
		void printHP(Battler *battler, s16 x, s16 y, s16 x2, bool onMaximum = false);
		void printSP(Battler *battler, s16 x, s16 y, s16 x2, bool onMaximum = false);
		void printExp(Battler *battler, s16 x, s16 y, s16 x2, bool onMaximum = false);
		void drawBattler(Battler *battler, s16 x, s16 y);
		void printItem(Item *item, u16 count, s16 x, s16 y, u16 width);

	protected:
		s16 m_x;
		s16 m_y;

		u16 m_width;
		u16 m_height;

		Rectangle m_cursor;
};

#endif // WINDOW_HPP_
