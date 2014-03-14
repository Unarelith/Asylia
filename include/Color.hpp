/*
 * =====================================================================================
 *
 *       Filename:  Color.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/03/2014 22:24:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
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
		
		u8 r;
		u8 g;
		u8 b;
		u8 a;
		
		static Color white;
		static Color black;
		static Color life;
};

#endif // COLOR_HPP_
