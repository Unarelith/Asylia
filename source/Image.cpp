/*
 * =====================================================================================
 *
 *       Filename:  Image.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/03/2014 22:12:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Image::Image() {
}

Image::Image(const char *filename) {
	SDL_RWops *image = SDL_RWFromFile(filename, "rb");
	m_surface = IMG_Load_RW(image, 1);
	
	if(!m_surface) {
		error("Failed to load image \"%s\": %s\n", filename, IMG_GetError());
		exit(EXIT_FAILURE);
	}
	
	m_width = m_surface->w;
	m_height = m_surface->h;
	
	m_texture = SDL_CreateTextureFromSurface(GameWindow::main->renderer(), m_surface);
	if(!m_texture) {
		error("Failed to create texture from image: %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	m_clipRect.x = 0;
	m_clipRect.y = 0;
	m_clipRect.w = m_width;
	m_clipRect.h = m_height;
	
	m_posRect.x = 0;
	m_posRect.y = 0;
	m_posRect.w = m_width;
	m_posRect.h = m_height;
}

Image::Image(SDL_Surface *surface) {
	m_surface = surface;
	
	m_width = m_surface->w;
	m_height = m_surface->h;
	
	m_texture = SDL_CreateTextureFromSurface(GameWindow::main->renderer(), m_surface);
	
	m_clipRect.x = 0;
	m_clipRect.y = 0;
	m_clipRect.w = m_width;
	m_clipRect.h = m_height;
	
	m_posRect.x = 0;
	m_posRect.y = 0;
	m_posRect.w = m_width;
	m_posRect.h = m_height;
}

Image::~Image() {
	SDL_FreeSurface(m_surface);
	SDL_DestroyTexture(m_texture);
}

void Image::reload(const char *filename) {
	SDL_FreeSurface(m_surface);
	SDL_DestroyTexture(m_texture);
	
	SDL_RWops *image = SDL_RWFromFile(filename, "rb");
	m_surface = IMG_Load_RW(image, 1);
	
	if(!m_surface) {
		error("Failed to load image \"%s\": %s\n", filename, IMG_GetError());
		exit(EXIT_FAILURE);
	}
	
	m_width = m_surface->w;
	m_height = m_surface->h;
	
	m_texture = SDL_CreateTextureFromSurface(GameWindow::main->renderer(), m_surface);
	if(!m_texture) {
		error("Failed to create texture from image: %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	m_clipRect.x = 0;
	m_clipRect.y = 0;
	m_clipRect.w = m_width;
	m_clipRect.h = m_height;
	
	m_posRect.x = 0;
	m_posRect.y = 0;
	m_posRect.w = m_width;
	m_posRect.h = m_height;
}

void Image::renderCopy() {
	SDL_RenderCopy(GameWindow::main->renderer(), m_texture, &m_clipRect, &m_posRect);
}

void Image::render(s16 x, s16 y, u16 w, u16 h, s16 clipX, s16 clipY, s16 clipW, s16 clipH) {
	if(x != -1) m_posRect.x = x;
	if(y != -1) m_posRect.y = y;
	if(w != 0) m_posRect.w = w;
	if(h != 0) m_posRect.h = h;
	
	if(clipX != -1) m_clipRect.x = clipX;
	if(clipY != -1) m_clipRect.y = clipY;
	if(clipW > 0) m_clipRect.w = clipW;
	if(clipH > 0) m_clipRect.h = clipH;
	
	renderCopy();
}

void Image::setPosRect(s16 x, s16 y, u16 w, u16 h) {
	m_posRect.x = x;
	m_posRect.y = y;
	m_posRect.w = w;
	m_posRect.h = h;
}

void Image::setClipRect(s16 x, s16 y, u16 w, u16 h) {
	m_clipRect.x = x;
	m_clipRect.y = y;
	m_clipRect.w = w;
	m_clipRect.h = h;
}

