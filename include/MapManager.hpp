/*
 * =====================================================================================
 *
 *       Filename:  MapManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/03/2014 19:14:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef MAPMANAGER_HPP_
#define MAPMANAGER_HPP_

#define MAP_POS(x, y, area) (u16)((x) + (y) * sqrt((double)MapManager::areaSizes[area]))

namespace MapManager {
	void init();
	void free();
	
	void initTilesets();
	void initMaps();
	
	extern Tileset **tilesets;
	extern Map ***maps;
	
	extern u16 nbTilesets;
	extern u16 nbAreas;
	extern u16 *areaSizes;
	
	extern Map *currentMap;
}

void getNonPassableTiles(const char *filename, Tileset *tileset);
bool passable(s16 x, s16 y);

#endif // MAPMANAGER_HPP_
