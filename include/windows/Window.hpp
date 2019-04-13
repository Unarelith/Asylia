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

#include <gk/core/Rect.hpp>
#include <gk/graphics/Text.hpp>

#include "Battler.hpp"

class Window : public gk::Drawable, public gk::Transformable {
	public:
		Window(s16 x, s16 y, u16 width, u16 height);

		s16 x() const { return getPosition().x; }
		s16 y() const { return getPosition().y; }

		u16 width() const { return m_width; }
		u16 height() const { return m_height; }

		void setX(s16 x) { setPosition(x, getPosition().y); }
		void setY(s16 y) { setPosition(getPosition().x, y); }

		void setWidth(u16 width) { m_width = width; }
		void setHeight(u16 height) { m_height = height; }

		void setCursorVisible(bool isCursorVisible) { m_isCursorVisible = isCursorVisible; }

		void printStat(s16 x, s16 y, const std::string &statName, s32 statValue, u16 nameWidth, u16 width, u16 max, gk::RenderTarget &target, gk::RenderStates states) const;
		void printName(Battler *battler, s16 x, s16 y, u16 width, gk::RenderTarget &target, gk::RenderStates states) const;
		void printState(Battler *battler, s16 x, s16 y, u16 width, gk::RenderTarget &target, gk::RenderStates states) const;
		void printLevel(Battler *battler, s16 x, s16 y, s16 x2, gk::RenderTarget &target, gk::RenderStates states) const;
		void printHP(Battler *battler, s16 x, s16 y, s16 x2, bool onMaximum, gk::RenderTarget &target, gk::RenderStates states) const;
		void printSP(Battler *battler, s16 x, s16 y, s16 x2, bool onMaximum, gk::RenderTarget &target, gk::RenderStates states) const;
		void printExp(Battler *battler, s16 x, s16 y, s16 x2, bool onMaximum, gk::RenderTarget &target, gk::RenderStates states) const;
		void drawBattler(Battler *battler, s16 x, s16 y, gk::RenderTarget &target, gk::RenderStates states) const;
		void printItem(Item *item, u16 count, s16 x, s16 y, u16 width, gk::RenderTarget &target, gk::RenderStates states) const;

	protected:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;
		void drawWindow(int x, int y, u16 width, u16 height, gk::RenderTarget &target, gk::RenderStates states) const;
		void drawCursor(int x, int y, u16 width, u16 height, gk::RenderTarget &target, gk::RenderStates states) const;
		void drawImagePart(const gk::IntRect &posRect, const gk::IntRect &clipRect, gk::RenderTarget &target, gk::RenderStates states) const;

		u16 m_width;
		u16 m_height;

		gk::IntRect m_cursorRect;

		mutable gk::Image m_window{"texture-interface-window"}; // FIXME
		mutable gk::Text m_text{"font-default", 18}; // FIXME

		bool m_isCursorVisible = true;
};

#endif // WINDOW_HPP_
