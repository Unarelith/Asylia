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
#include <gk/core/input/GamePad.hpp>
#include <gk/core/ApplicationStateStack.hpp>
#include <gk/resource/ResourceHandler.hpp>

#include "EventInterpreter.hpp"
#include "GameKey.hpp"
#include "Map.hpp"
#include "MapState.hpp"
#include "MenuState.hpp"
#include "ResourceHelper.hpp"
#include "Player.hpp"

MapState::MapState() {
	ResourceHelper::getCurrentMap()->load();

	m_currentMap = ResourceHelper::getCurrentTilemap();
	if (!m_currentMap) {
		m_currentMap = &gk::ResourceHandler::getInstance().get<Tilemap>("map0-0-0");
		m_currentMap->initEvents();
	}

	// Map::scrollX = 0;
	// Map::scrollY = 0;

	gk::AudioPlayer::playMusic("music-theme");
}

void MapState::update() {
	if(gk::GamePad::isKeyPressedOnce(GameKey::Start)) {
		gk::AudioPlayer::playSound("sound-confirm");
		gk::ApplicationStateStack::getInstance().push<MenuState>(this);
		return;
	}

	ResourceHelper::getPlayer()->move();
	ResourceHelper::getPlayer()->update();

	// Map::centerMapWithObject(ResourceHelper::getPlayer()->x(),
	// 						 ResourceHelper::getPlayer()->y(),
	// 						 ResourceHelper::getPlayer()->frameWidth(),
	// 						 ResourceHelper::getPlayer()->frameHeight());

	if (m_currentMap)
		m_currentMap->updateEvents();
}

void MapState::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	if (m_currentMap)
		target.draw(*m_currentMap, states);

	target.draw(*ResourceHelper::getPlayer(), states);

	// ResourceHelper::getCurrentMap()->renderOverlay();
}

