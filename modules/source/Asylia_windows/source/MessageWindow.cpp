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

MessageWindow::MessageWindow() : TextWindow(40, 0, 0, 0) { 
	m_width = GameWindow::main->width() - m_x * 2;
	m_height = GameWindow::main->height() / 3;
	m_y = GameWindow::main->height() - m_height - 20;
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

