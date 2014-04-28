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
	
	choices.push_back(_t("Cancel"));
	choices.push_back(_t("TitleScreen"));
	choices.push_back(_t("Quit"));
	
	m_cmdwin = new CommandWindow(192, choices);
	m_cmdwin->x(GameWindow::main->width() / 2 - m_cmdwin->width() / 2);
	m_cmdwin->y(GameWindow::main->height() / 2 - m_cmdwin->height() / 2);
}

EndActivity::~EndActivity() {
}

void EndActivity::update() {
	m_cmdwin->update();
	
	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		Sound::Effect::play(Sound::Effect::confirm);
		
		switch(m_cmdwin->pos()) {
			case 0:
				ActivityManager::pop();
				break;
			case 1:
#ifndef NO_TITLESCREEN
				while(ActivityManager::top()->type() != Type::TitleScreen) {
					ActivityManager::pop();
				}
#else
				while(ActivityManager::size() > 0) {
					ActivityManager::pop();
				}
				ActivityManager::push(new TitleActivity);
#endif
				break;
			case 2:
				SDL_Delay(100);
				Game::quit = true;
				delete m_cmdwin;
				m_cmdwin = NULL;
				break;
			default: break;
		}
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
		Sound::Effect::play(Sound::Effect::back);
		ActivityManager::pop();
	}
}

void EndActivity::render() {
	if(m_cmdwin) m_cmdwin->draw();
}

