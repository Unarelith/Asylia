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

CommandWindow *win;

GameActivity::GameActivity() {
	MapManager::currentMap = MapManager::maps[0][0];
	MapManager::currentMap->load();
	
	std::vector<std::string> choices;
	
	choices.push_back("Yes");
	choices.push_back("No");
	
	win = new CommandWindow(20, 20, 300, choices);
}

GameActivity::~GameActivity() {
}

void GameActivity::processInputs() {
	
}

void GameActivity::update() {
	win->update();
}

void GameActivity::render() {
	MapManager::currentMap->render();
	MapManager::currentMap->renderOverlay();
	
	win->draw();
}

