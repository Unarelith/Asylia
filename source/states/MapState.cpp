/*
 * =====================================================================================
 *
 *       Filename:  MapState.cpp
 *
 *    Description:
 *
 *        Created:  21/03/2014 18:23:05
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/audio/AudioPlayer.hpp>
#include <gk/core/ApplicationStateStack.hpp>

#include "EventInterpreter.hpp"
#include "Keyboard.hpp"
#include "MapState.hpp"
#include "MenuState.hpp"
#include "ResourceHelper.hpp"
#include "Player.hpp"

MapState::MapState() {
	LuaHandler::setInstance(m_luaHandler);
	EventManager::setInstance(m_eventManager);
	MapManager::setInstance(m_mapManager);

	m_luaHandler.init();
	m_eventManager.init();
	m_mapManager.init();

	m_luaHandler.bindClasses();

	m_mapManager.getCurrentMap()->load();

	gk::AudioPlayer::playMusic("music-theme");
}

void MapState::update() {
	if(Keyboard::isKeyPressedOnce(Keyboard::GameMenu)) {
		gk::AudioPlayer::playSound("sound-confirm");
		gk::ApplicationStateStack::getInstance().push<MenuState>(this);
		return;
	}

	ResourceHelper::getPlayer()->move();

	Map::centerMapWithObject(ResourceHelper::getPlayer()->x(),
							 ResourceHelper::getPlayer()->y(),
							 ResourceHelper::getPlayer()->frameWidth(),
							 ResourceHelper::getPlayer()->frameHeight());

	MapManager::getInstance().getCurrentMap()->eventsUpdate();
}

void MapState::render() {
	MapManager::getInstance().getCurrentMap()->render();

	for(u16 i = 0 ; i < MapManager::getInstance().getCurrentMap()->events().size() ; i++) {
		if(MapManager::getInstance().getCurrentMap()->events()[i]->y() < ResourceHelper::getPlayer()->y()) {
			MapManager::getInstance().getCurrentMap()->events()[i]->render();
		}
	}

	ResourceHelper::getPlayer()->render();

	for(u16 i = 0 ; i < MapManager::getInstance().getCurrentMap()->events().size() ; i++) {
		if(MapManager::getInstance().getCurrentMap()->events()[i]->y() >= ResourceHelper::getPlayer()->y()) {
			MapManager::getInstance().getCurrentMap()->events()[i]->render();
		}
	}

	MapManager::getInstance().getCurrentMap()->renderOverlay();
}

