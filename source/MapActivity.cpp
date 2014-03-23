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
	CharacterManager::free();
	
	MapManager::free();
	
	LuaHandler::free();
}

void MapActivity::init() {
	LuaHandler::init();
	
	MapManager::init();
	
	MapManager::currentMap = MapManager::maps[0][0];
	
	LuaHandler::bindClasses();
	
	MapManager::currentMap->load();
	
	CharacterManager::init();
}

void MapActivity::update() {
	if(Keyboard::isKeyPressedOnce(Keyboard::GameMenu)) {
		Sound::Effect::play(Sound::Effect::confirm);
		ActivityManager::push(new MenuActivity);
	}
	
	CharacterManager::player->move();
	
	GameWindow::main->centerViewportWithObject(CharacterManager::player->x(),
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

