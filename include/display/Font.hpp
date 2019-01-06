/*
 * =====================================================================================
 *
 *       Filename:  Font.hpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  22/03/2014 00:51:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef FONT_HPP_
#define FONT_HPP_

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

		void print(const char *str, u16 x, u16 y, FontSize size, Color color = Color::white);
		void printScaled(const char *str, u16 x, u16 y, u16 width, u16 height, FontSize size, Color color = Color::white);
		void printToImage(const char *str, u16 x, u16 y, Image *image, FontSize size, Color color = Color::white);
		void printScaledToImage(const char *str, u16 x, u16 y, u16 width, u16 height, Image *image, FontSize size, Color color = Color::white);
		void printTextBox(const char *str, u16 x, u16 y, u16 width, u16 height, FontSize size, Color color = Color::white);
		void printCentered(const char *str, u16 x, u16 y, u16 width, u16 height, FontSize size, Color color = Color::white);

		void printDamages(u16 damages, u16 x, u16 y, Color color);

		void setStyle(FontSize size, int style);

	private:
		TTF_Font *m_fontSmall;
		TTF_Font *m_fontMedium;
		TTF_Font *m_fontLarge;
		TTF_Font *m_fontMaxi;
};

#endif // FONT_HPP_
