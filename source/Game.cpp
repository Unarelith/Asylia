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
	Image test("graphics/interface/Interface.png");
	
	u16 viewportCenterX = GameWindow::main->width() / 2;
	u16 viewportCenterY = GameWindow::main->height() / 2;
	
	while(!quit) {
		if(TimeManager::isTimeToUpdate()) {
			ActivityManager::activities.top()->pollEvents();
			
			Keyboard::update();
			
			ActivityManager::activities.top()->processInputs();
			
			if(Keyboard::isKeyPressedWithDelay(Keyboard::GameUp, 200)) viewportCenterY--;
			if(Keyboard::isKeyPressedWithDelay(Keyboard::GameDown, 200)) viewportCenterY++;
			if(Keyboard::isKeyPressedWithDelay(Keyboard::GameLeft, 200)) viewportCenterX--;
			if(Keyboard::isKeyPressedWithDelay(Keyboard::GameRight, 200)) viewportCenterX++;
			
			ActivityManager::activities.top()->update();
			
			if(TimeManager::hasEnoughTimeToDraw()) {
				TimeManager::beginMeasuringRenderingTime();
				
				GameWindow::main->clear();
				
				ActivityManager::activities.top()->render();
				
				test.render(0, 0, 1920 / 1.2, 1280 / 1.2);
				
				GameWindow::main->centerViewportWithObject(viewportCenterX, viewportCenterY, 0, 0);
				GameWindow::main->update();
				
				TimeManager::endMeasuringRenderingTime();
			}
		} else {
			TimeManager::waitUntilItsTime();
		}
		
		TimeManager::measureFrameDuration();
	}
}

