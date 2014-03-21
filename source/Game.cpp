/*
 * =====================================================================================
 *
 *       Filename:  Game.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/03/2014 21:26:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

bool Game::quit = false;

Game::Game() {
	SDLManager::init();
	
	GameWindow::main = new GameWindow(APP_NAME);
	
	MapManager::init();
	
	ActivityManager::init();
}

Game::~Game() {
	MapManager::free();
	
	delete GameWindow::main;
	
	SDLManager::free();
}

void Game::mainLoop() {
	while(!quit) {
		if(TimeManager::isTimeToUpdate()) {
			ActivityManager::activities.top()->pollEvents();
			
			Keyboard::update();
			
			ActivityManager::activities.top()->processInputs();
			
			ActivityManager::activities.top()->update();
			
			if(TimeManager::hasEnoughTimeToDraw()) {
				TimeManager::beginMeasuringRenderingTime();
				
				GameWindow::main->clear();
				
				ActivityManager::activities.top()->render();
				
				GameWindow::main->update();
				
				TimeManager::endMeasuringRenderingTime();
			}
		} else {
			TimeManager::waitUntilItsTime();
		}
		
		TimeManager::measureFrameDuration();
	}
}

