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

Activity::Activity(Activity *parent) {
	m_type = Type::None;
	
	m_parent = parent;
	
	m_background = SDL_CreateTexture(GameWindow::main->renderer(), 372645892, SDL_TEXTUREACCESS_TARGET, GameWindow::main->width(), GameWindow::main->height());
	SDL_SetTextureBlendMode(m_background, SDL_BLENDMODE_BLEND);
}

Activity::~Activity() {
	if(m_background) SDL_DestroyTexture(m_background);
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

void Activity::renderBackground() {
	SDL_Rect posRect = {0, 0, GameWindow::main->width(), GameWindow::main->height()};
	SDL_RenderCopy(GameWindow::main->renderer(), m_background, NULL, &posRect);
}

void Activity::screenshot(Activity *activity) {
	SDL_SetRenderTarget(GameWindow::main->renderer(), m_background);
	activity->render();
	SDL_SetRenderTarget(GameWindow::main->renderer(), NULL);
}

