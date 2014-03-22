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
		
		void draw();
		
	protected:
		s16 m_x;
		s16 m_y;
		
		u16 m_width;
		u16 m_height;
};

#endif // WINDOW_HPP_
