/*
 * =====================================================================================
 *
 *       Filename:  SelectableWindow.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 00:45:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef SELECTABLEWINDOW_HPP_
#define SELECTABLEWINDOW_HPP_

class SelectableWindow : public Window {
	public:
		SelectableWindow(s16 x, s16 y, u16 width, u16 height);
		~SelectableWindow();
		
		void updateCursor();
		void update();
		
	protected:
		u8 m_itemMax;
		u8 m_columnMax;
		
		s8 m_pos;
};

#endif // SELECTABLEWINDOW_HPP_
