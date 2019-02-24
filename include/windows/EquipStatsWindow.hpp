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

		// void draw(Item *currentItem = nullptr);

	private:
		Actor *m_actor;
};

#endif // EQUIPSTATSWINDOW_HPP_
