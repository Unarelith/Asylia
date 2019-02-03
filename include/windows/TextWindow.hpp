/*
 * =====================================================================================
 *
 *       Filename:  TextWindow.hpp
 *
 *    Description:
 *
 *        Created:  23/03/2014 18:19:48
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TEXTWINDOW_HPP_
#define TEXTWINDOW_HPP_

#include "Window.hpp"

class TextWindow : public Window {
	public:
		TextWindow(s16 x, s16 y, u16 width, u16 height);

		void draw(const std::string &text);
};

#endif // TEXTWINDOW_HPP_
