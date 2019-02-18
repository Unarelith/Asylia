/*
 * =====================================================================================
 *
 *       Filename:  Font.hpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 00:51:45
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef FONT_HPP_
#define FONT_HPP_

#include <gk/core/SDLHeaders.hpp>

#include "Image.hpp"

typedef enum {
	FONT_SMALL = 11,
	FONT_MEDIUM = 16,
	FONT_LARGE = 18,
	FONT_MAXI = 22
} FontSize;

class Font {
	public:
		Font(const char *filename);
		~Font();

		void print(const char *str, u16 x, u16 y, FontSize size, const gk::Color &color = gk::Color::White);
		void printScaled(const char *str, u16 x, u16 y, u16 width, u16 height, FontSize size, const gk::Color &color = gk::Color::White);
		void printToImage(const char *str, u16 x, u16 y, Image *image, FontSize size, const gk::Color &color = gk::Color::White);
		void printScaledToImage(const char *str, u16 x, u16 y, u16 width, u16 height, Image *image, FontSize size, const gk::Color &color = gk::Color::White);
		void printTextBox(const char *str, u16 x, u16 y, u16 width, u16 height, FontSize size, const gk::Color &color = gk::Color::White);
		void printCentered(const char *str, u16 x, u16 y, u16 width, u16 height, FontSize size, const gk::Color &color = gk::Color::White);

		void printDamages(u16 damages, u16 x, u16 y, const gk::Color &color);

		void setStyle(FontSize size, int style);

	private:
		TTF_Font *m_fontSmall;
		TTF_Font *m_fontMedium;
		TTF_Font *m_fontLarge;
		TTF_Font *m_fontMaxi;
};

#endif // FONT_HPP_
