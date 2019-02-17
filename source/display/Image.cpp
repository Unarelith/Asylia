/*
 * =====================================================================================
 *
 *       Filename:  Image.cpp
 *
 *    Description:
 *
 *        Created:  20/03/2014 22:12:00
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Debug.hpp"
#include "GameWindow.hpp"
#include "Image.hpp"

Image::Image() {
	m_filename = "";

	m_texture = nullptr;

	m_hidden = false;
}

Image::Image(const Image &img) {
	if(img.m_filename != "") {
		m_texture = nullptr;

		reload(img.m_filename.c_str());
	} else {
		m_texture = img.m_texture;
	}

	m_width = img.m_width;
	m_height = img.m_height;

	m_clipRect.x = img.m_clipRect.x;
	m_clipRect.y = img.m_clipRect.y;
	m_clipRect.w = img.m_clipRect.w;
	m_clipRect.h = img.m_clipRect.h;

	m_posRect.x = img.m_posRect.x;
	m_posRect.y = img.m_posRect.y;
	m_posRect.w = img.m_posRect.w;
	m_posRect.h = img.m_posRect.h;

	m_hidden = false;
}

Image::Image(const char *filename) {
	m_filename = filename;

	SDL_RWops *image = SDL_RWFromFile(filename, "rb");
	SDL_Surface *surface = IMG_Load_RW(image, 1);

	if(strcmp(filename, "") && !surface) {
		error("Failed to load image \"%s\": %s\n", filename, IMG_GetError());
		exit(EXIT_FAILURE);
	}

	if(surface) {
		m_width = surface->w;
		m_height = surface->h;
	} else {
		m_width = m_height = 32;
	}

	m_texture = SDL_CreateTextureFromSurface(GameWindow::main->renderer(), surface);
	if(strcmp(filename, "") && !m_texture) {
		error("Failed to create texture from image: %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_SetTextureBlendMode(m_texture, SDL_BLENDMODE_BLEND);
	SDL_FreeSurface(surface);

	m_clipRect.x = 0;
	m_clipRect.y = 0;
	m_clipRect.w = m_width;
	m_clipRect.h = m_height;

	m_posRect.x = 0;
	m_posRect.y = 0;
	m_posRect.w = m_width;
	m_posRect.h = m_height;

	m_hidden = false;
}

Image::Image(SDL_Surface *surface) {
	m_filename = "";

	m_width = surface->w;
	m_height = surface->h;

	m_texture = SDL_CreateTextureFromSurface(GameWindow::main->renderer(), surface);
	SDL_SetTextureBlendMode(m_texture, SDL_BLENDMODE_BLEND);
	SDL_FreeSurface(surface);

	m_clipRect.x = 0;
	m_clipRect.y = 0;
	m_clipRect.w = m_width;
	m_clipRect.h = m_height;

	m_posRect.x = 0;
	m_posRect.y = 0;
	m_posRect.w = m_width;
	m_posRect.h = m_height;

	m_hidden = false;
}

Image::~Image() {
	if(m_texture) {
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;
	}
}

void Image::reload(const char *filename) {
	m_filename = filename;

	if(m_texture) SDL_DestroyTexture(m_texture);

	SDL_RWops *image = SDL_RWFromFile(filename, "rb");
	SDL_Surface *surface = IMG_Load_RW(image, 1);

	if(!surface) {
		error("Failed to load image \"%s\": %s\n", filename, IMG_GetError());
		exit(EXIT_FAILURE);
	}

	m_width = surface->w;
	m_height = surface->h;

	m_texture = SDL_CreateTextureFromSurface(GameWindow::main->renderer(), surface);
	if(!m_texture) {
		error("Failed to create texture from image: %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_SetTextureBlendMode(m_texture, SDL_BLENDMODE_BLEND);
	SDL_FreeSurface(surface);

	m_clipRect.x = 0;
	m_clipRect.y = 0;
	m_clipRect.w = m_width;
	m_clipRect.h = m_height;

	m_posRect.x = 0;
	m_posRect.y = 0;
	m_posRect.w = m_width;
	m_posRect.h = m_height;

	m_hidden = false;
}

void Image::reload(SDL_Surface *surface) {
	m_filename = "";

	if(m_texture) SDL_DestroyTexture(m_texture);

	m_width = surface->w;
	m_height = surface->h;

	m_texture = SDL_CreateTextureFromSurface(GameWindow::main->renderer(), surface);
	SDL_SetTextureBlendMode(m_texture, SDL_BLENDMODE_BLEND);
	SDL_FreeSurface(surface);

	m_clipRect.x = 0;
	m_clipRect.y = 0;
	m_clipRect.w = m_width;
	m_clipRect.h = m_height;

	m_posRect.x = 0;
	m_posRect.y = 0;
	m_posRect.w = m_width;
	m_posRect.h = m_height;

	m_hidden = false;
}

void Image::renderCopy() {
	if(m_texture) {
		if(!m_hidden) {
			SDL_RenderCopy(GameWindow::main->renderer(), m_texture, &m_clipRect, &m_posRect);
		}
	} else {
		GameWindow::main->drawFillRect(m_posRect.x, m_posRect.y, m_posRect.w, m_posRect.h, Color(255, 255, SDL_GetTicks() % 256));
	}
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

