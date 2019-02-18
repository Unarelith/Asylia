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

#include "EventInterpreter.hpp"
#include "GameKey.hpp"
#include "Map.hpp"
#include "MapState.hpp"
#include "MenuState.hpp"
#include "ResourceHelper.hpp"
#include "Player.hpp"

MapState::MapState() {
	ResourceHelper::getCurrentMap()->load();

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

	Map::centerMapWithObject(ResourceHelper::getPlayer()->x(),
							 ResourceHelper::getPlayer()->y(),
							 ResourceHelper::getPlayer()->frameWidth(),
							 ResourceHelper::getPlayer()->frameHeight());

	ResourceHelper::getCurrentMap()->eventsUpdate();
}

void MapState::render() {
	ResourceHelper::getCurrentMap()->render();

	for(u16 i = 0 ; i < ResourceHelper::getCurrentMap()->events().size() ; i++) {
		if(ResourceHelper::getCurrentMap()->events()[i]->y() < ResourceHelper::getPlayer()->y()) {
			ResourceHelper::getCurrentMap()->events()[i]->render();
		}
	}

	ResourceHelper::getPlayer()->render();

	for(u16 i = 0 ; i < ResourceHelper::getCurrentMap()->events().size() ; i++) {
		if(ResourceHelper::getCurrentMap()->events()[i]->y() >= ResourceHelper::getPlayer()->y()) {
			ResourceHelper::getCurrentMap()->events()[i]->render();
		}
	}

	ResourceHelper::getCurrentMap()->renderOverlay();
}

