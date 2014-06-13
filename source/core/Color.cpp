/*
 * =====================================================================================
 *
 *       Filename:  Color.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/03/2014 22:26:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Color Color::white(255, 255, 255);
Color Color::black(0, 0, 0);
Color Color::system(192, 224, 255);
Color Color::disabled(192, 204, 195);
Color Color::red(237, 52, 36);
Color Color::green(52, 255, 36);

Color::Color(u8 _r, u8 _g, u8 _b, u8 _a) {
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}

Color::~Color() {
}

