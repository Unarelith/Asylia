/*
 * =====================================================================================
 *
 *       Filename:  GameActivity.cpp
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

GameActivity::GameActivity() {
	m_type = Type::Game;
	
	MapManager::currentMap = MapManager::maps[0][0];
	MapManager::currentMap->load();
}

GameActivity::~GameActivity() {
}

void GameActivity::processInputs() {
	
}

void GameActivity::update() {
	if(Keyboard::isKeyPressed(Keyboard::GameMenu)) {
		Sound::Effect::play(Sound::Effect::confirm);
		ActivityManager::activities.push(new MenuActivity);
	}
}

void GameActivity::render() {
	MapManager::currentMap->render();
	MapManager::currentMap->renderOverlay();
}

