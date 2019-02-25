/*
 * =====================================================================================
 *
 *       Filename:  SelectableWindow.hpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 00:45:42
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SELECTABLEWINDOW_HPP_
#define SELECTABLEWINDOW_HPP_

#include <memory>

#include "InfoWindow.hpp"

class SelectableWindow : public Window {
	public:
		SelectableWindow(s16 x, s16 y, u16 width, u16 height);

		void updateCursor();
		void update();

		u16 itemMax() const { return m_itemMax; }

		void columnMax(u8 columnMax) { m_columnMax = columnMax; }

		s16 pos() const { return m_pos; }
		void pos(u16 pos) { m_pos = pos; }

		static u16 lastPos;

	protected:
		u16 m_itemMax;
		u8 m_columnMax;

		s16 m_pos;

		u8 m_scroll;
};

#endif // SELECTABLEWINDOW_HPP_
