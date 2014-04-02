/*
 * =====================================================================================
 *
 *       Filename:  Activity.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/03/2014 21:21:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Activity::Activity() {
	m_type = Type::None;
}

Activity::~Activity() {
}

void Activity::pollEvents() {
	SDL_Event event;
	while(SDL_PollEvent(&event) != 0) {
		switch(event.type) {
			case SDL_QUIT:
				Game::quit = true;
				break;
			case SDL_FINGERDOWN:
			case SDL_FINGERMOTION:
				Keyboard::updatePad(&event);
				break;
			case SDL_FINGERUP:
				Keyboard::resetPad(&event, true);
				break;
			case SDL_APP_WILLENTERBACKGROUND:
				Game::paused = true;
				break;
			case SDL_APP_WILLENTERFOREGROUND:
				Game::quit = true; // FIXME: See #9
				Game::paused = false;
				if(ActivityManager::top()->type() == Type::Map) {
					ActivityManager::push(new MenuActivity);
				}
				break;
			case SDL_APP_TERMINATING:
				if(ActivityManager::top()->type() != Type::GameEnd) {
					ActivityManager::push(new EndActivity);
				}
				break;
			default:
				break;
		}
	}
}

