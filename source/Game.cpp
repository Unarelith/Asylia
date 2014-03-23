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
				
				GameWindow::main->update();
				
				TimeManager::endMeasuringRenderingTime();
			}
		} else {
			TimeManager::waitUntilItsTime();
		}
		
		TimeManager::measureFrameDuration();
	}
}

