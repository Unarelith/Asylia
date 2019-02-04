/*
 * =====================================================================================
 *
 *       Filename:  GameWindow.cpp
 *
 *    Description:
 *
 *        Created:  14/03/2014 22:10:43
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Config.hpp"
#include "Debug.hpp"
#include "GameWindow.hpp"

GameWindow *GameWindow::main = nullptr;

void GameWindow::open(const char *caption) {
#ifdef __ANDROID__
	SDL_DisplayMode current;
	SDL_GetCurrentDisplayMode(0, &current);

	info("Current display: %dx%d", current.w, current.h);

	m_width = current.w / 1.25;
	m_height = current.h / 1.25;
#else
	m_width = WIN_DEFAULT_WIDTH;
	m_height = WIN_DEFAULT_HEIGHT;
#endif

	m_window.reset(SDL_CreateWindow(caption, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_SHOWN));
	if(!m_window) {
		error("Error while initializing window: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	m_renderer.reset(SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED));
	if(!m_renderer) {
		error("Renderer couldn't be created: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

#ifdef __ANDROID__
	SDL_RenderSetLogicalSize(m_renderer, m_width, m_height);
#endif
}

void GameWindow::clear() {
	SDL_RenderClear(m_renderer.get());
}

void GameWindow::update() {
	SDL_RenderPresent(m_renderer.get());
}

void GameWindow::setRendererColor(const Color &color) {
	SDL_SetRenderDrawColor(m_renderer.get(), color.r, color.g, color.b, color.a);
}

void GameWindow::drawRect(s16 x, s16 y, u16 w, u16 h, const Color &c) {
	setRendererColor(c);

	SDL_Rect r = {x, y, w, h};

	SDL_RenderDrawRect(m_renderer.get(), &r);

	setRendererColor(Color::black);
}

void GameWindow::drawFillRect(s16 x, s16 y, u16 w, u16 h, const Color &c) {
	setRendererColor(c);

	SDL_Rect r = {x, y, w, h};

	SDL_RenderFillRect(m_renderer.get(), &r);

	setRendererColor(Color::black);
}

