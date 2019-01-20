/*
 * =====================================================================================
 *
 *       Filename:  Rectangle.hpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 12:28:03
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

struct Rectangle {
	Rectangle() {};

	Rectangle(s16 _x, s16 _y, u16 _width, u16 _height) :
		x(_x), y(_y), width(_width), height(_height) {};

	s16 x;
	s16 y;

	u16 width;
	u16 height;
};

typedef struct Rectangle Rectangle;

#endif // RECTANGLE_HPP_
