/*
 * =====================================================================================
 *
 *       Filename:  Font.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 00:59:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Font::Font(const char *filename) {
	m_fontSmall  = TTF_OpenFont(filename, FONT_SMALL);
	m_fontMedium = TTF_OpenFont(filename, FONT_MEDIUM);
	m_fontLarge  = TTF_OpenFont(filename, FONT_LARGE);
}

Font::~Font() {
	TTF_CloseFont(m_fontSmall);
	TTF_CloseFont(m_fontMedium);
	TTF_CloseFont(m_fontLarge);
}

void Font::print(const char *str, u16 x, u16 y, FontSize size, Color color) {
	TTF_Font *font = NULL;
	
	switch(size) {
		case FONT_SMALL:  font = m_fontSmall;		break;
		case FONT_MEDIUM: font = m_fontMedium;		break;
		case FONT_LARGE:  font = m_fontLarge;		break;
		default:		  error("Bad font size");	return;
	}
	
	SDL_Surface *textSurface = TTF_RenderUTF8_Blended(font, str, SDL_Color{color.r, color.g, color.b, color.a});
	Image textToDisplay(textSurface);
	
	textToDisplay.render(x, y);
}

void Font::printScaled(const char *str, u16 x, u16 y, u16 width, u16 height, FontSize size, Color color) {
	TTF_Font *font = NULL;
	
	switch(size) {
		case FONT_SMALL:  font = m_fontSmall;		break;
		case FONT_MEDIUM: font = m_fontMedium;		break;
		case FONT_LARGE:  font = m_fontLarge;		break;
		default:		  error("Bad font size");	return;
	}
	
	SDL_Surface *textSurface = TTF_RenderUTF8_Blended(font, str, SDL_Color{color.r, color.g, color.b, color.a});
	
	if(width > textSurface->w) width = textSurface->w;
	if(height > textSurface->h) height = textSurface->h;
	
	Image textToDisplay(textSurface);
	
	textToDisplay.render(x, y, width, height);
}

void Font::printToImage(const char *str, u16 x, u16 y, Image *image, FontSize size, Color color) {
	TTF_Font *font = NULL;
	
	switch(size) {
		case FONT_SMALL:  font = m_fontSmall;		break;
		case FONT_MEDIUM: font = m_fontMedium;		break;
		case FONT_LARGE:  font = m_fontLarge;		break;
		default:		  error("Bad font size");	return;
	}
	
	SDL_Surface *text = TTF_RenderUTF8_Blended(font, str, SDL_Color{color.r, color.g, color.b, color.a});
	
	image->reload(text);
	image->setPosRect(x, y, image->width(), image->height());
}

void Font::printScaledToImage(const char *str, u16 x, u16 y, u16 width, u16 height, Image *image, FontSize size, Color color) {
	TTF_Font *font = NULL;
	
	switch(size) {
		case FONT_SMALL:  font = m_fontSmall;		break;
		case FONT_MEDIUM: font = m_fontMedium;		break;
		case FONT_LARGE:  font = m_fontLarge;		break;
		default:		  error("Bad font size");	return;
	}
	
	SDL_Surface *text = TTF_RenderUTF8_Blended(font, str, SDL_Color{color.r, color.g, color.b, color.a});
	
	if(width > text->w) width = text->w;
	if(height > text->h) height = text->h;
	
	image->reload(text);
	image->setPosRect(x, y, width, height);
}

void Font::printTextBox(const char *str, u16 x, u16 y, u16 width, u16 height, FontSize size, Color color) {
	TTF_Font *font = NULL;
	
	switch(size) {
		case FONT_SMALL:  font = m_fontSmall;		break;
		case FONT_MEDIUM: font = m_fontMedium;		break;
		case FONT_LARGE:  font = m_fontLarge;		break;
		default:		  error("Bad font size");	return;
	}
	
	SDL_Surface *textSurface = TTF_RenderUTF8_Blended_Wrapped(font, str, SDL_Color{color.r, color.g, color.b, color.a}, width);
	Image textToDisplay(textSurface);
	
	textToDisplay.render(x, y, 0, 0, 0, 0, width, height);
}

void Font::printCentered(const char *str, u16 x, u16 y, u16 width, u16 height, FontSize size, Color color) {
	TTF_Font *font = NULL;
	
	switch(size) {
		case FONT_SMALL:  font = m_fontSmall;		break;
		case FONT_MEDIUM: font = m_fontMedium;		break;
		case FONT_LARGE:  font = m_fontLarge;		break;
		default:		  error("Bad font size");	return;
	}
	
	SDL_Surface *textSurface = TTF_RenderUTF8_Blended(font, str, SDL_Color{color.r, color.g, color.b, color.a});
	Image textToDisplay(textSurface);
	
	textToDisplay.render(x + width / 2 - textToDisplay.width() / 2,
						 y + height / 2 - textToDisplay.height() / 2);
}

void Font::printDamages(u16 damages, u16 x, u16 y, Color color) {
	TTF_SetFontKerning(m_fontLarge, 0);
	
	x += GameWindow::main->viewportX();
	y += GameWindow::main->viewportY();
	
	TTF_SetFontOutline(m_fontLarge, 3);
	
	print(to_string(damages).c_str(), x - 3, y - 3, FONT_LARGE, Color::black);
	
	TTF_SetFontOutline(m_fontLarge, 2);
	
	print(to_string(damages).c_str(), x - 2, y - 2, FONT_LARGE, Color::white);
	
	TTF_SetFontOutline(m_fontLarge, 0);
	
	print(to_string(damages).c_str(), x, y, FONT_LARGE, color);
	
	TTF_SetFontKerning(m_fontLarge, 1);
}

void Font::setStyle(FontSize size, int style) {
	TTF_Font *font = NULL;
	
	switch(size) {
		case FONT_SMALL:  font = m_fontSmall;		break;
		case FONT_MEDIUM: font = m_fontMedium;		break;
		case FONT_LARGE:  font = m_fontLarge;		break;
		default:		  error("Bad font size");	return;
	}
	
	TTF_SetFontStyle(font, style);
}

