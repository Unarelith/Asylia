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

void Activity::pollEvents(bool *quit) {
	SDL_Event event;
	while(SDL_PollEvent(&event) != 0) {
		switch(event.type) {
			case SDL_QUIT:
				Game::quit = true;
				if(quit) *quit = true;
				break;
#ifdef __ANDROID__
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

