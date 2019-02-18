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

#include <memory>

#include "Map.hpp"

#define MAP_POS(x, y, area) (u16)((x) + (y) * sqrt((double)MapManager::getInstance().getAreaSize(area)))

class MapManager : public Singleton<MapManager> {
	public:
		void init();

		Map *getCurrentMap() { return m_currentMap; }
		void setCurrentMap(Map *currentMap) { m_currentMap = currentMap; }

		Map *getMap(u16 area, u16 x, u16 y) { return m_maps[area][MAP_POS(x, y, area)].get(); }
		size_t getAreaSize(u16 area) { return m_maps[area].size(); }

	private:
		std::vector<std::vector<std::unique_ptr<Map>>> m_maps;

		Map *m_currentMap = nullptr;
};

bool passable(s16 x, s16 y);

#endif // MAPMANAGER_HPP_
