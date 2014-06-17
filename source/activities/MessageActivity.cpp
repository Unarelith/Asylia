/*
 * =====================================================================================
 *
 *       Filename:  MessageActivity.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/03/2014 18:22:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

MessageActivity::MessageActivity(std::string message, Activity *parent) : Activity(parent) {
	m_type = Type::Message;
	
	m_parent = parent;
	if(m_parent == NULL) {
		m_parent = ActivityManager::top();
	}
	
	m_txtwin = new TextWindow(40, GameWindow::main->height() - GameWindow::main->height() / 3 - 20, GameWindow::main->width() - 80, GameWindow::main->height() / 3);
	
	m_cmdwin = new CommandWindow(m_txtwin->x(), 0, 150, 0);
	
	m_message = message;
}

MessageActivity::~MessageActivity() {
	delete m_cmdwin;
	
	delete m_txtwin;
}

void MessageActivity::updateCmdwinSize() {
	u16 sizeMax = 0;
	for(auto &it : m_cmdwin->commands()) {
		if(it.first.size() > sizeMax) sizeMax = it.first.size();
	}
	
	m_cmdwin->width(sizeMax * 20 + 40);
	m_cmdwin->height(m_cmdwin->commands().size() * 32 + 32);
	m_cmdwin->y(m_txtwin->y() - m_cmdwin->height());
}

void MessageActivity::update() {
	if(m_cmdwin->commands().size() > 0) {
		m_cmdwin->update();
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		if(m_cmdwin->commands().size() > 0) {
			Sound::Effect::play(Sound::Effect::confirm);
		}
		
		ActivityManager::pop();
		ActivityManager::top()->update();
	}
}

void MessageActivity::render() {
	SDL_RenderCopy(GameWindow::main->renderer(), m_background, NULL, NULL);
	
	if(m_cmdwin->commands().size() > 0) {
		m_cmdwin->draw();
	}
	
	m_txtwin->draw(m_message);
}

