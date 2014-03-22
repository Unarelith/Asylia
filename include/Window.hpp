/*
 * =====================================================================================
 *
 *       Filename:  Window.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 00:30:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef WINDOW_HPP_
#define WINDOW_HPP_

class Window {
	public:
		Window(s16 x, s16 y, u16 width, u16 height);
		~Window();
		
		void update();
		
		void drawCursor(s16 x, s16 y, u16 width, u16 height);
		void draw();
		
		void x(s16 x) { m_x = x; }
		void y(s16 y) { m_y = y; }
		
		u16 width() const { return m_width; }
		u16 height() const { return m_height; }
		
	protected:
		s16 m_x;
		s16 m_y;
		
		u16 m_width;
		u16 m_height;
		
		Rectangle m_cursor;
};

#endif // WINDOW_HPP_
