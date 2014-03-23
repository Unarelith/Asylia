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

DialogActivity::DialogActivity() {
	m_type = Type::Dialog;
	
	m_msgwin = new MessageWindow();
}

DialogActivity::~DialogActivity() {
	delete m_msgwin;
}

void DialogActivity::update() {
	m_msgwin->update();
	
	if(m_msgwin->messages().size() == 0) {
		ActivityManager::pop();
	}
}

void DialogActivity::render() {
	MapActivity::render();
	
	m_msgwin->draw();
}

