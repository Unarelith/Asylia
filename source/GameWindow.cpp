/*
 * =====================================================================================
 *
 *       Filename:  GameWindow.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/03/2014 22:10:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

GameWindow *GameWindow::main = NULL;

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
	
	m_viewportX = 0;
	m_viewportY = 0;
	
	m_viewportW = m_width;
	m_viewportH = m_height;
	
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

void GameWindow::updateViewportPosition(s16 x, s16 y) {
	if(MapManager::currentMap) {
		if(x < 0) x = 0;
		if(x + m_width >= MapManager::currentMap->width() * MapManager::currentMap->tileset()->tileWidth) x = MapManager::currentMap->width() * MapManager::currentMap->tileset()->tileWidth - m_width - 1;
		if(y < 0) y = 0;
		if(y + m_height >= MapManager::currentMap->height() * MapManager::currentMap->tileset()->tileHeight) y = MapManager::currentMap->height() * MapManager::currentMap->tileset()->tileHeight - m_height - 1;
	}
	
	m_viewportX = x;
	m_viewportY = y;
	
	if(m_viewportX + m_width > m_viewportW) m_viewportW += m_width;
	if(m_viewportY + m_height > m_viewportH) m_viewportH += m_height;
	
	SDL_Rect viewportRect = {-x, y - m_viewportH + m_height, m_viewportW, m_viewportH};
	SDL_RenderSetViewport(m_renderer, &viewportRect);
}

void GameWindow::centerViewportWithObject(s16 x, s16 y, u16 w, u16 h) {
	updateViewportPosition(x - (m_width - w) / 2, y - (m_height - h) / 2);
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

