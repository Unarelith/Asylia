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

GameWindow::GameWindow(const char *caption) {
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

	m_window = SDL_CreateWindow(caption, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_SHOWN);
	if(!m_window) {
		error("Error while initializing window: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if(!m_renderer) {
		error("Renderer couldn't be created: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

#ifdef __ANDROID__
	SDL_RenderSetLogicalSize(m_renderer, m_width, m_height);
#endif
}

GameWindow::~GameWindow() {
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
}

void GameWindow::clear() {
	SDL_RenderClear(m_renderer);
}

void GameWindow::update() {
	SDL_RenderPresent(m_renderer);
}

void GameWindow::setRendererColor(Color color) {
	SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
}

void GameWindow::drawRect(s16 x, s16 y, u16 w, u16 h, Color c) {
	setRendererColor(c);

	SDL_Rect r = {x, y, w, h};

	SDL_RenderDrawRect(m_renderer, &r);

	setRendererColor(Color::black);
}

void GameWindow::drawFillRect(s16 x, s16 y, u16 w, u16 h, Color c) {
	setRendererColor(c);

	SDL_Rect r = {x, y, w, h};

	SDL_RenderFillRect(m_renderer, &r);

	setRendererColor(Color::black);
}

