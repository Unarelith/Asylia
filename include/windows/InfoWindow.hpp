/*
 * =====================================================================================
 *
 *       Filename:  InfoWindow.hpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  05/04/2014 17:01:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef INFOWINDOW_HPP_
#define INFOWINDOW_HPP_

class InfoWindow : public Window {
	public:
		InfoWindow(s16 x, s16 y, u16 width, u16 height);
		~InfoWindow();

		void drawTextScaled(std::string text);
		void drawTextCentered(std::string text);
};

#endif // INFOWINDOW_HPP_
