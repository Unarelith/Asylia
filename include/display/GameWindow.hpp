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

#include <memory>

#include "Color.hpp"
#include "SDLHeaders.hpp"
#include <gk/core/IntTypes.hpp>

class GameWindow {
	public:
		GameWindow() = default;

		void open(const char *caption);

		void clear();

		void update();

		void setRendererColor(const Color &color);

		void drawRect(s16 x, s16 y, u16 w, u16 h, const Color &c);

		void drawFillRect(s16 x, s16 y, u16 w, u16 h, const Color &c);

		SDL_Renderer *renderer() const { return m_renderer.get(); }

		u16 width() const { return m_width; }
		u16 height() const { return m_height; }

		static GameWindow *main;

	private:
		using SDL_WindowPtr = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;
		using SDL_RendererPtr = std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>;

		SDL_WindowPtr m_window{nullptr, SDL_DestroyWindow};
		SDL_RendererPtr m_renderer{nullptr, SDL_DestroyRenderer};

		u16 m_width;
		u16 m_height;
};

#endif // GAMEWINDOW_HPP_
