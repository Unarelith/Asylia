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

#ifdef __ANDROID__
std::string to_string(int n) {
	std::stringstream s; s << n; return s.str();
}
#endif

Game::Game() {
	LuaHandler::init();
	
	SDLManager::init();
	
	GameWindow::main = new GameWindow(APP_NAME);
	
	Sound::init();
	
	Interface::init();
	
	ActivityManager::init();
}

Game::~Game() {
	Interface::free();
	
	Sound::free();
	
	delete GameWindow::main;
	
	SDLManager::free();
	
	LuaHandler::free();
	
	exit(EXIT_SUCCESS);
}

void Game::mainLoop() {
	while(!quit) {
		if(TimeManager::isTimeToUpdate()) {
			ActivityManager::top()->pollEvents();
			
			Keyboard::update();
			
			ActivityManager::top()->update();
			
			if(TimeManager::hasEnoughTimeToDraw()) {
				TimeManager::beginMeasuringRenderingTime();
				
				GameWindow::main->clear();
				
				ActivityManager::top()->render();
				
				Interface::renderHUD();
				
				GameWindow::main->update();
				
				TimeManager::endMeasuringRenderingTime();
			}
		} else {
			TimeManager::waitUntilItsTime();
		}
		
		TimeManager::measureFrameDuration();
	}
}

