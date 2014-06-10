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

MenuActivity::MenuActivity(Activity *parent) : Activity(parent) {
	m_type = Type::Menu;
	
	loadCommandWindow();
	
	m_actorChoicewin = new ActorChoiceWindow(150, 0, GameWindow::main->width() - 150, GameWindow::main->height());
}

MenuActivity::~MenuActivity() {
	delete m_actorChoicewin;
	
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
	choices.push_back(_t("Quit"));
	
	m_cmdwin = new CommandWindow(150, choices);
}

void MenuActivity::update() {
	m_cmdwin->update();
	
	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		Sound::Effect::play(Sound::Effect::confirm);
		
		switch(m_cmdwin->pos()) {
			case 0:
				ActivityManager::push(new ItemActivity(this));
				break;
			case 1: break;
			case 2:
				ActivityManager::push(new EquipActivity(this));
				break;
			case 3: break;
			case 4: break;
			case 5:
				ActivityManager::push(new SettingsActivity(this));
				break;
			case 6:
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
	SDL_RenderCopy(GameWindow::main->renderer(), m_background, NULL, NULL);
	
	m_cmdwin->draw(ActivityManager::top() == this);
	
	m_actorChoicewin->draw();
}

