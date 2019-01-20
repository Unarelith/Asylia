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

class TextWindow : public Window {
	public:
		TextWindow(s16 x, s16 y, u16 width, u16 height);
		~TextWindow();

		void draw(std::string text);
};

#endif // TEXTWINDOW_HPP_
