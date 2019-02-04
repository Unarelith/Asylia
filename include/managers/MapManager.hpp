/*
 * =====================================================================================
 *
 *       Filename:  MapManager.hpp
 *
 *    Description:
 *
 *        Created:  21/03/2014 19:14:22
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MAPMANAGER_HPP_
#define MAPMANAGER_HPP_

#include "Map.hpp"

#define MAP_POS(x, y, area) (u16)((x) + (y) * sqrt((double)MapManager::maps[area].size()))

class MapManager {
	public:
		static void init();
		static void free();

		static void initTilesets();
		static void initMaps();

		static std::vector<Tileset*> tilesets;
		static std::vector<std::vector<Map*>> maps;

		static Map *getCurrentMap() { return currentMap; }
		static Map *currentMap;
};

void getNonPassableTiles(const char *filename, Tileset *tileset);
bool passable(s16 x, s16 y);

#endif // MAPMANAGER_HPP_
