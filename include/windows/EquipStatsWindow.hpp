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

class EquipStatsWindow : public Window {
	public:
		EquipStatsWindow(Actor *actor);
		~EquipStatsWindow();

		void draw(Item *currentItem = NULL);

	private:
		Actor *m_actor;
};

#endif // EQUIPSTATSWINDOW_HPP_
