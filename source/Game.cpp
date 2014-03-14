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
	SDLinit();
	
#ifdef __ANDROID__
	SDL_DisplayMode current;
	SDL_GetCurrentDisplayMode(0, &current);
	
	info("Current display: %dx%d", current.w, current.h);
	
	GameWindow::main = new GameWindow(APP_NAME, current.w, current.h);
#else
	GameWindow::main = new GameWindow(APP_NAME, 640, 480);
#endif
}

Game::~Game() {
	delete GameWindow::main;
	
	SDLquit();
}

void Game::SDLinit() {
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		error("SDL init error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	if(!IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) {
		error("SDL_image init error: %s\n", IMG_GetError());
		exit(EXIT_FAILURE);
	}
	
	if(TTF_Init() < 0) {
		error("SDL_ttf init error: %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}
	
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) {
		error("SDL_mixer init error: %s\n", Mix_GetError());
		exit(EXIT_FAILURE);
	}
	Mix_AllocateChannels(32);
	Mix_Volume(1, MIX_MAX_VOLUME / 2);
	
	if(!SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1")) {
		warn("Warning: VSync not enabled!");
	}
}

void Game::SDLquit() {
	Mix_CloseAudio();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void Game::mainLoop(void (*processInputs_)(void), void (*update_)(void), void (*render_)(void)) {
	while(!quit) {
		if(TimeManager::isTimeToUpdate()) {
			(*processInputs_)();
			(*update_)();
			if(TimeManager::hasEnoughTimeToDraw()) {
				(*render_)();
				GameWindow::main->update();
			}
		} else {
			TimeManager::waitUntilItsTime();
		}
		
		TimeManager::measureFrameDuration();
	}
}

void Game::processInputs() {
	pollEvents();
}

void Game::update() {
	
}

void Game::render() {
	TimeManager::beginMeasuringRenderingTime();
	
	GameWindow::main->clear();
	
	
	
	TimeManager::endMeasuringRenderingTime();
}

void Game::pollEvents(bool *quit) {
	SDL_Event event;
	while(SDL_PollEvent(&event) != 0) {
		switch(event.type) {
			case SDL_QUIT:
				Game::quit = true;
				if(quit) *quit = true;
				break;
#ifndef __ANDROID__
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym) {
					case SDLK_ESCAPE:
						Game::quit = true;
						if(quit) *quit = true;
						break;
					default: break;
				}
#else
			case SDL_FINGERDOWN:
			case SDL_FINGERMOTION:
				Keyboard::updatePad(&event);
				break;
			case SDL_FINGERUP:
				Keyboard::resetPad(&event, true);
				break;
			case SDL_APP_WILLENTERBACKGROUND:
				continue;
#endif
			default:
				break;
		}
	}
}

