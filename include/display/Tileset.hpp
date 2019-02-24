/*
 * =====================================================================================
 *
 *       Filename:  Tileset.hpp
 *
 *    Description:
 *
 *        Created:  21/03/2014 19:12:55
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TILESET_HPP_
#define TILESET_HPP_

#include <gk/graphics/Image.hpp>

struct Tileset {
	Tileset() : tileWidth(16), tileHeight(16) {}

	gk::Image tiles;

	u16 tileWidth;
	u16 tileHeight;

	u16 *nonPassableLayer;
};

#endif // TILESET_HPP_
