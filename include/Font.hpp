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
	FONT_SMALL = 14,
	FONT_MEDIUM = 18,
	FONT_LARGE = 22
} FontSize;

class Font {
	public:
		Font(const char *filename);
		~Font();
		
		void print(const char *str, u16 x, u16 y, FontSize size, Color color = Color::black);
		void printTextScaled(const char *str, u16 x, u16 y, u16 width, u16 height, FontSize size, Color color = Color::black);
		void printTextBox(const char *str, u16 x, u16 y, u16 width, u16 height, FontSize size, Color color = Color::black);
		
	private:
		TTF_Font *m_fontSmall;
		TTF_Font *m_fontMedium;
		TTF_Font *m_fontLarge;
};

#endif // FONT_HPP_
