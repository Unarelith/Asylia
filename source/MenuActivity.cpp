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
	
	loadCommandWindow();
}

MenuActivity::~MenuActivity() {
	delete m_cmdwin;
}

void MenuActivity::loadCommandWindow() {
	std::vector<std::string> choices;
	
	choices.push_back(_t("Items"));
	choices.push_back(_t("Skills"));
	choices.push_back(_t("Equip"));
	choices.push_back(_t("State"));
	choices.push_back(_t("Save"));
	choices.push_back(_t("Settings"));
	choices.push_back("Battle test");
	choices.push_back(_t("Quit"));
	
	m_cmdwin = new CommandWindow(150, choices);
}

void MenuActivity::update() {
	m_cmdwin->update();
	
	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		Sound::Effect::play(Sound::Effect::confirm);
		
		switch(m_cmdwin->pos()) {
			case 0:
				ActivityManager::push(new ItemActivity);
				break;
			case 1: break;
			case 2:
				ActivityManager::push(new EquipActivity);
				break;
			case 3: break;
			case 4: break;
			case 5:
				ActivityManager::push(new SettingsActivity);
				break;
			case 6:
				ActivityManager::push(new BattleActivity);
				break;
			case 7:
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

