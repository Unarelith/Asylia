/*
 * =====================================================================================
 *
 *       Filename:  MessageWindow.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  23/03/2014 18:49:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

MessageWindow::MessageWindow() : TextWindow(40, 300, 560, 160) { // FIXME
}

MessageWindow::~MessageWindow() {
}

void MessageWindow::update() {
	TextWindow::update();
	
	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		if(m_messages.size() != 0) {
			m_messages.pop();
		}
	}
}

void MessageWindow::draw() {
	TextWindow::draw(m_messages.front());
}

