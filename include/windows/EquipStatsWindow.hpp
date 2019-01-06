/*
 * =====================================================================================
 *
 *       Filename:  EquipStatsWindow.hpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  13/04/2014 17:27:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef EQUIPSTATSWINDOW_HPP_
#define EQUIPSTATSWINDOW_HPP_

class EquipStatsWindow : public Window {
	public:
		EquipStatsWindow(Actor *actor);
		~EquipStatsWindow();

		void draw(Item *currentItem = NULL);

	private:
		Actor *m_actor;
};

#endif // EQUIPSTATSWINDOW_HPP_
