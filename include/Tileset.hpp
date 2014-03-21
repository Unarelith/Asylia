/*
 * =====================================================================================
 *
 *       Filename:  Tileset.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/03/2014 19:12:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef TILESET_HPP_
#define TILESET_HPP_

struct Tileset {
	Tileset() : tileWidth(16), tileHeight(16) {}
	
	Image *tiles;
	
	u16 tileWidth;
	u16 tileHeight;
	
	u16 *nonPassableLayer;
};

#endif // TILESET_HPP_
