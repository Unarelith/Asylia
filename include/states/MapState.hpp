/*
 * =====================================================================================
 *
 *       Filename:  MapState.hpp
 *
 *    Description:
 *
 *        Created:  21/03/2014 18:19:43
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MAPSTATE_HPP_
#define MAPSTATE_HPP_

#include <gk/core/ApplicationState.hpp>

#include "LuaHandler.hpp"
#include "CharacterManager.hpp"
#include "EventManager.hpp"
#include "MapManager.hpp"
#include "QuestManager.hpp"

class MapState : public gk::ApplicationState {
	public:
		MapState();

		void update() override;
		void render() override;

	private:
		LuaHandler m_luaHandler;
		EventManager m_eventManager;
		MapManager m_mapManager;
		QuestManager m_questManager;
		CharacterManager m_characterManager;
};

#endif // MAPSTATE_HPP_
