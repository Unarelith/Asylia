/*
 * =====================================================================================
 *
 *       Filename:  InfoWindow.hpp
 *
 *    Description:
 *
 *        Created:  05/04/2014 17:01:05
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef INFOWINDOW_HPP_
#define INFOWINDOW_HPP_

#include "Window.hpp"

class InfoWindow : public Window {
	public:
		InfoWindow(s16 x, s16 y, u16 width, u16 height);
		~InfoWindow();

		void drawTextScaled(std::string text);
		void drawTextCentered(std::string text);
};

#endif // INFOWINDOW_HPP_
