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

#include "LuaHandler.hpp"
#include "AnimationManager.hpp"
#include "ApplicationState.hpp"
#include "BattlerManager.hpp"
#include "CharacterManager.hpp"
#include "EventManager.hpp"
#include "ItemManager.hpp"
#include "MapManager.hpp"
#include "QuestManager.hpp"
#include "SpriteAnimationManager.hpp"
#include "TroopManager.hpp"

class MapState : public ApplicationState {
	public:
		MapState();

		void update();
		void render();

	private:
		LuaHandler m_luaHandler;
		SpriteAnimationManager m_spriteAnimationManager;
		AnimationManager m_animationManager;
		EventManager m_eventManager;
		MapManager m_mapManager;
		ItemManager m_itemManager;
		QuestManager m_questManager;
		CharacterManager m_characterManager;
		BattlerManager m_battlerManager;
		TroopManager m_troopManager;
};

#endif // MAPSTATE_HPP_
