/*
 * =====================================================================================
 *
 *       Filename:  EndActivity.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 17:47:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

EndActivity::EndActivity() {
	std::vector<std::string> choices;
	
	choices.push_back("Cancel");
	choices.push_back("Go to Title");
	choices.push_back("Quit");
	
	m_cmdwin = new CommandWindow(192, choices);
	m_cmdwin->x(GameWindow::main->width() / 2 - m_cmdwin->width() / 2);
	m_cmdwin->y(GameWindow::main->height() / 2 - m_cmdwin->height() / 2);
}

EndActivity::~EndActivity() {
	delete m_cmdwin;
}

void EndActivity::processInputs() {
	
}

void EndActivity::update() {
	m_cmdwin->update();
	
	if(Keyboard::isKeyPressedWithDelay(Keyboard::GameAttack, 100)) {
		Sound::Effect::play(Sound::Effect::confirm);
		
		switch(m_cmdwin->pos()) {
			case 0:
				ActivityManager::activities.pop();
				break;
			case 1:
#ifndef NO_TITLESCREEN
				while(ActivityManager::activities.top()->type() != Type::TitleScreen) {
					ActivityManager::activities.pop();
				}
#else
				while(ActivityManager::activities.size() > 0) {
					ActivityManager::activities.pop();
				}
				ActivityManager::activities.push(new TitleActivity);
#endif
				break;
			case 2:
				SDL_Delay(100);
				Game::quit = true;
				break;
			default: break;
		}
	}
}

void EndActivity::render() {
	m_cmdwin->draw();
}

