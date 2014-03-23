/*
 * =====================================================================================
 *
 *       Filename:  MenuActivity.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/03/2014 18:23:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

MenuActivity::MenuActivity() {
	m_type = Type::Menu;
	
	std::vector<std::string> choices;
	
	choices.push_back("Items");
	choices.push_back("Skills");
	choices.push_back("Equip");
	choices.push_back("State");
	choices.push_back("Save");
	choices.push_back("Quit");
	
	m_cmdwin = new CommandWindow(150, choices);
}

MenuActivity::~MenuActivity() {
	delete m_cmdwin;
}

void MenuActivity::update() {
	m_cmdwin->update();
	
	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		Sound::Effect::play(Sound::Effect::confirm);
		
		switch(m_cmdwin->pos()) {
			case 0: break;
			case 1: break;
			case 2: break;
			case 3: break;
			case 4: break;
			case 5:
				ActivityManager::push(new EndActivity);
				break;
			default: break;
		}
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
		Sound::Effect::play(Sound::Effect::back);
		ActivityManager::pop();
	}
}

void MenuActivity::render() {
	MapActivity::render();
	
	m_cmdwin->draw();
}

