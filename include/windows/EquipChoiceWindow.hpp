/*
 * =====================================================================================
 *
 *       Filename:  EquipChoiceWindow.hpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  17/04/2014 20:38:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef EQUIPCHOICEWINDOW_HPP_
#define EQUIPCHOICEWINDOW_HPP_

class EquipChoiceWindow : public SelectableWindow {
	public:
		EquipChoiceWindow(Equipment *equipment);
		~EquipChoiceWindow();

		void draw(bool drawCursor = true);

	private:
		Equipment *m_equipment;
};

#endif // EQUIPCHOICEWINDOW_HPP_
