/*
 * =====================================================================================
 *
 *       Filename:  EquipStatsWindow.hpp
 *
 *    Description:
 *
 *        Created:  13/04/2014 17:27:24
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef EQUIPSTATSWINDOW_HPP_
#define EQUIPSTATSWINDOW_HPP_

#include "Actor.hpp"
#include "Window.hpp"

class EquipStatsWindow : public Window {
	public:
		EquipStatsWindow(Actor *actor);

		void setCursorItem(Item *currentItem) { m_currentItem = currentItem; }

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const;

		Item *m_currentItem = nullptr;

		Actor *m_actor;
};

#endif // EQUIPSTATSWINDOW_HPP_
