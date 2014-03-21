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
	MapManager::currentMap = MapManager::maps[0][0];
	MapManager::currentMap->load();
	
	LuaHandler::doString("img = Image(\"graphics/interface/Interface.png\")");
}

void GameActivity::processInputs() {
	
}

void GameActivity::update() {
	
}

void GameActivity::render() {
	MapManager::currentMap->render();
	MapManager::currentMap->renderOverlay();
	
	LuaHandler::doString("img:renderCopy()");
}

