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
#include <gk/core/Exception.hpp>

#include "Config.hpp"
#include "GameWindow.hpp"

GameWindow *GameWindow::main = nullptr;

void GameWindow::open(const char *caption) {
	m_width = SCREEN_WIDTH;
	m_height = SCREEN_HEIGHT;

	m_window.reset(SDL_CreateWindow(caption, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_SHOWN));
	if(!m_window) {
		throw EXCEPTION("Error while initializing window:", SDL_GetError());
	}

	m_renderer.reset(SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED));
	if(!m_renderer) {
		throw EXCEPTION("Renderer couldn't be created:", SDL_GetError());
	}
}

void GameWindow::clear() {
	SDL_RenderClear(m_renderer.get());
}

void GameWindow::update() {
	SDL_RenderPresent(m_renderer.get());
}

