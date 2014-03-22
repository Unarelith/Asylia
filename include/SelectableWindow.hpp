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
		SelectableWindow(s16 x, s16 y, u16 width, u16 height, std::string *choices);
		~SelectableWindow();
		
		void drawSelectionMarker(u16 width, u16 posX, u16 posY);
		void draw();
		
	protected:
		std::string *m_choices;
		
		u8 m_rowMax;
		u8 m_columnMax;
};

#endif // SELECTABLEWINDOW_HPP_
