/*
 * =====================================================================================
 *
 *       Filename:  MapActivity.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  21/03/2014 18:23:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

MapActivity::MapActivity() {
	m_type = Type::Map;
}

MapActivity::~MapActivity() {
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

void MapActivity::init() {
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

void MapActivity::update() {
	if(Keyboard::isKeyPressedOnce(Keyboard::GameMenu)) {
		Sound::Effect::play(Sound::Effect::confirm);
		ActivityManager::push(new MenuActivity(this));
		return;
	}

	CharacterManager::player->move();

	Map::centerMapWithObject(CharacterManager::player->x(),
							 CharacterManager::player->y(),
							 CharacterManager::player->frameWidth(),
							 CharacterManager::player->frameHeight());

	MapManager::currentMap->eventsUpdate();
}

void MapActivity::render() {
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

