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
	
#ifdef __ANDROID__
	SDL_DisplayMode current;
	SDL_GetCurrentDisplayMode(0, &current);
	
	info("Current display: %dx%d", current.w, current.h);
	
	GameWindow::main = new GameWindow(APP_NAME, current.w, current.h);
#else
	GameWindow::main = new GameWindow(APP_NAME, 640, 480);
#endif
	
	ActivityManager::init();
}

Game::~Game() {
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

