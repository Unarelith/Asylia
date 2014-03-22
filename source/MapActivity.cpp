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
}

void MapActivity::init() {
	MapManager::init();
	MapManager::currentMap = MapManager::maps[0][0];
	MapManager::currentMap->load();
	
	CharacterManager::init();
}

void MapActivity::update() {
	if(Keyboard::isKeyPressed(Keyboard::GameMenu)) {
		Sound::Effect::play(Sound::Effect::confirm);
		ActivityManager::activities.push(new MenuActivity);
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
	
	CharacterManager::player->render();
	
	MapManager::currentMap->eventsRender();
	
	MapManager::currentMap->renderOverlay();
}

