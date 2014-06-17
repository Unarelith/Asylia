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
		
		u16 itemMax() const { return m_itemMax; }
		
		s16 pos() const { return m_pos; }
		void pos(u16 pos) { m_pos = pos; }
		
		static u16 lastPos;
		
	protected:
		u16 m_itemMax;
		u8 m_columnMax;
		
		s16 m_pos;
		
		u8 m_scroll;
		
		InfoWindow *m_infoWindow;
};

#endif // SELECTABLEWINDOW_HPP_
