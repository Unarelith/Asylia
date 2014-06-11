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
	
	m_cmdwin = new CommandWindow(m_x, m_y, 150, 0);
	m_choiceMode = false;
}

MessageWindow::~MessageWindow() {
}

void MessageWindow::update() {
	TextWindow::update();
	
	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		if(m_choiceMode) {
			Sound::Effect::play(Sound::Effect::confirm);
			m_choiceMode = false;
			
			for(std::vector<std::string>::iterator it = m_messages.begin() ; it != m_messages.end() ; it++) {
				if((*it).substr(0, 1) == "[") {
					if((*it).substr(0, 3) != std::string("[") + to_string(m_cmdwin->pos()) + "]") {
						m_messages.erase(it);
						it = m_messages.begin();
					} else {
						(*it).replace(0, 3, "");
					}
				}
			}
			
			m_cmdwin->pos(0);
		}
		
		if(m_messages.size() != 0) {
			m_messages.erase(m_messages.begin());
		}
	}
	
	if(m_messages.size() != 0 && m_messages.front().substr(0, 8) == "<Battle>") {
		ActivityManager::startBattle(atoi(m_messages.front().substr(8, m_messages.front().size() - 8).c_str()));
		m_messages.erase(m_messages.begin());
	}
	
	if(!m_choiceMode) {
		if(m_messages.size() != 0 && m_messages.front().substr(0, 9) == "<Command>") {
			m_messages.front().replace(0, 9, "");
			m_choiceMode = true;
			updateCmdwinSize();
		}
	} else {
		m_cmdwin->update();
	}
}

void MessageWindow::updateCmdwinSize() {
	u16 maxSize = 0;
	for(auto &it : m_cmdwin->commands()) {
		if(std::get<0>(it).size() > maxSize) maxSize = std::get<0>(it).size();
	}
	
	m_cmdwin->width(maxSize * 20 + 40);
	m_cmdwin->height(m_cmdwin->commands().size() * 32 + 32);
	m_cmdwin->y(m_y - m_cmdwin->height());
}

void MessageWindow::draw() {
	TextWindow::draw(m_messages.front());
	
	if(m_choiceMode) m_cmdwin->draw();
}

