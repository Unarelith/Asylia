/*
 * =====================================================================================
 *
 *       Filename:  GameWindow.hpp
 *
 *    Description:
 *
 *        Created:  14/03/2014 22:06:27
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef GAMEWINDOW_HPP_
#define GAMEWINDOW_HPP_

#include "Color.hpp"
#include "SDLHeaders.hpp"
#include "Types.hpp"

class GameWindow {
	public:
		GameWindow(const char *caption);
		~GameWindow();

		void clear();

		void update();

		void setRendererColor(Color color);

		void drawRect(s16 x, s16 y, u16 w, u16 h, Color c);

		void drawFillRect(s16 x, s16 y, u16 w, u16 h, Color c);

		SDL_Renderer *renderer() const { return m_renderer; }

		u16 width() const { return m_width; }
		u16 height() const { return m_height; }

		static GameWindow *main;

	private:
		SDL_Window *m_window;
		SDL_Renderer *m_renderer;

		u16 m_width;
		u16 m_height;
};

#endif // GAMEWINDOW_HPP_
