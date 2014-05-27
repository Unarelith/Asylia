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
	BattleManager::free();
	
	BattlerManager::free();
	
	CharacterManager::free();
	
	ItemManager::free();
	
	MapManager::free();
	
	EventManager::free();
	
	AnimationManager::free();
	
	SpriteAnimationManager::free();
	
	LuaHandler::free();
}

void MapActivity::init() {
	LuaHandler::init();
	
	SpriteAnimationManager::init();
	
	AnimationManager::init();
	
	EventManager::init();
	
	MapManager::init();
	
	LuaHandler::bindClasses();
	
	MapManager::currentMap->load();
	
	ItemManager::init();
	
	CharacterManager::init();
	
	BattlerManager::init();
	
	BattleManager::init();
	
	Sound::Music::play(Sound::Music::theme, -1);
}

void MapActivity::update() {
	if(Keyboard::isKeyPressedOnce(Keyboard::GameMenu)) {
		Sound::Effect::play(Sound::Effect::confirm);
		ActivityManager::push(new MenuActivity(this));
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

