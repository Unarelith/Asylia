/*
 * =====================================================================================
 *
 *       Filename:  DialogActivity.cpp
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

DialogActivity::DialogActivity(Activity *parent) : Activity(parent) {
	m_type = Type::Dialog;
	
	m_parent = parent;
	if(m_parent == NULL) {
		m_parent = ActivityManager::top();
	}
	
	m_msgwin = new MessageWindow();
}

DialogActivity::~DialogActivity() {
	delete m_msgwin;
}

void DialogActivity::update() {
	m_msgwin->update();
	
	if(m_msgwin->messages().size() == 0) {
		ActivityManager::pop();
		ActivityManager::top()->update();
	}
	
	if(ActivityManager::top()->type() == Activity::Type::BattleAct) {
		m_msgwin->eraseCurrentMessage();
	}
}

void DialogActivity::render() {
	SDL_RenderCopy(GameWindow::main->renderer(), m_background, NULL, NULL);
	
	m_msgwin->draw();
}

