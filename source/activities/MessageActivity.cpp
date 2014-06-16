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
	m_type = Type::Dialog;
	
	m_parent = parent;
	if(m_parent == NULL) {
		m_parent = ActivityManager::top();
	}
	
	m_txtwin = new TextWindow(40, GameWindow::main->height() - GameWindow::main->height() / 3 - 20, GameWindow::main->width() - 80, GameWindow::main->height() / 3);
	
	m_message = message;
}

MessageActivity::~MessageActivity() {
	delete m_txtwin;
}

void MessageActivity::update() {
	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		ActivityManager::pop();
		ActivityManager::top()->update();
	}
}

void MessageActivity::render() {
	SDL_RenderCopy(GameWindow::main->renderer(), m_background, NULL, NULL);
	
	m_txtwin->draw(m_message);
}

