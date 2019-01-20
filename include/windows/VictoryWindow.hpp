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

class VictoryWindow : public Window {
	public:
		VictoryWindow(Battle *battle);
		~VictoryWindow();

		void draw();

	private:
		Battle *m_battle;

		Inventory m_inventory;
		u16 m_itemsNb;
};

#endif // VICTORYWINDOW_HPP_
