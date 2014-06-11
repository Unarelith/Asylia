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

EndActivity::EndActivity(bool disableCancel) {
	m_cmdwin = new CommandWindow(192);
	if(!disableCancel) m_cmdwin->addCommand("Cancel");
	m_cmdwin->addCommand("TitleScreen");
	m_cmdwin->addCommand("Quit");
	
	m_cmdwin->x(GameWindow::main->width() / 2 - m_cmdwin->width() / 2);
	m_cmdwin->y(GameWindow::main->height() / 2 - m_cmdwin->height() / 2);
}

EndActivity::~EndActivity() {
}

void EndActivity::update() {
	m_cmdwin->update();
	
	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		if(m_cmdwin->disabled(m_cmdwin->pos())) {
			Sound::Effect::play(Sound::Effect::blocked);
			return;
		}
		
		Sound::Effect::play(Sound::Effect::confirm);
		
		u8 n = m_cmdwin->pos();
		if(m_cmdwin->commands().size() == 2) {
			n++;
		}
		
		switch(n) {
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

