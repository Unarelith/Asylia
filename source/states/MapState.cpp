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
#include "LuaHandler.hpp"
#include "AnimationManager.hpp"
#include "BattlerManager.hpp"
#include "CharacterManager.hpp"
#include "EventInterpreter.hpp"
#include "EventManager.hpp"
#include "ItemManager.hpp"
#include "Keyboard.hpp"
#include "MapManager.hpp"
#include "MapState.hpp"
#include "MenuState.hpp"
#include "QuestManager.hpp"
#include "Sound.hpp"
#include "SpriteAnimationManager.hpp"
#include "ApplicationStateStack.hpp"
#include "TroopManager.hpp"

MapState::MapState() {
	m_type = Type::Map;
}

MapState::~MapState() {
	TroopManager::free();

	BattlerManager::free();

	CharacterManager::free();

	QuestManager::free();

	ItemManager::free();

	MapManager::free();

	EventManager::free();

	AnimationManager::free();

	SpriteAnimationManager::free();

	LuaHandler::free();

	EventInterpreter::free();
}

void MapState::init() {
	LuaHandler::init();

	SpriteAnimationManager::init();

	AnimationManager::init();

	EventManager::init();

	MapManager::init();

	LuaHandler::bindClasses();

	ItemManager::init();

	QuestManager::init();

	CharacterManager::init();

	BattlerManager::init();

	CharacterManager::loadActorsTeam();

	TroopManager::init();

	MapManager::currentMap->load();

	Sound::Music::play(Sound::Music::theme, -1);
}

void MapState::update() {
	if(Keyboard::isKeyPressedOnce(Keyboard::GameMenu)) {
		Sound::Effect::play(Sound::Effect::confirm);
		ApplicationStateStack::getInstance().push<MenuState>(this);
		return;
	}

	CharacterManager::player->move();

	Map::centerMapWithObject(CharacterManager::player->x(),
							 CharacterManager::player->y(),
							 CharacterManager::player->frameWidth(),
							 CharacterManager::player->frameHeight());

	MapManager::currentMap->eventsUpdate();
}

void MapState::render() {
	MapManager::currentMap->render();

	for(u16 i = 0 ; i < MapManager::currentMap->events().size() ; i++) {
		if(MapManager::currentMap->events()[i]->y() < CharacterManager::player->y()) {
			MapManager::currentMap->events()[i]->render();
		}
	}

	CharacterManager::player->render();

	for(u16 i = 0 ; i < MapManager::currentMap->events().size() ; i++) {
		if(MapManager::currentMap->events()[i]->y() >= CharacterManager::player->y()) {
			MapManager::currentMap->events()[i]->render();
		}
	}

	MapManager::currentMap->renderOverlay();
}

