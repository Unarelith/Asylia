/*
 * =====================================================================================
 *
 *       Filename:  EquipActivity.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/04/2014 19:51:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

EquipActivity::EquipActivity() {
	m_itemwin = new EquipItemWindow(1, 1);
}

EquipActivity::~EquipActivity() {
	delete m_itemwin;
}

void EquipActivity::update() {
	m_itemwin->update();
	
	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		Sound::Effect::play(Sound::Effect::confirm);
		
		switch(m_itemwin->pos()) {
			default: break;
		}
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
		Sound::Effect::play(Sound::Effect::back);
		ActivityManager::pop();
	}
}

void EquipActivity::render() {
	MenuActivity::render();
	
	m_itemwin->draw();
}

