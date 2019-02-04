/*
 * =====================================================================================
 *
 *       Filename:  VictoryWindow.hpp
 *
 *    Description:
 *
 *        Created:  31/05/2014 16:20:49
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef VICTORYWINDOW_HPP_
#define VICTORYWINDOW_HPP_

#include "Battle.hpp"
#include "Window.hpp"

class VictoryWindow : public Window {
	public:
		VictoryWindow();

		void init(Battle *battle);

		void draw();

	private:
		Battle *m_battle = nullptr;

		Inventory m_inventory;
		u16 m_itemsNb;
};

#endif // VICTORYWINDOW_HPP_
