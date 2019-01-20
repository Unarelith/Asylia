/*
 * =====================================================================================
 *
 *       Filename:  Color.hpp
 *
 *    Description:
 *
 *        Created:  14/03/2014 22:24:55
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef COLOR_HPP_
#define COLOR_HPP_

class Color {
	public:
		Color(u8 _r, u8 _g, u8 _b, u8 _a = 255);
		~Color();

		void invert() { r=255-r; g=255-g; b=255-b; }

		Color operator+(Color c) { return Color(r + c.r, g + c.g, b + c.b, a + c.a); }

		u8 r;
		u8 g;
		u8 b;
		u8 a;

		static Color white;
		static Color black;
		static Color system;
		static Color disabled;
		static Color red;
		static Color green;
};

#endif // COLOR_HPP_
