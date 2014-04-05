/*
 * =====================================================================================
 *
 *       Filename:  ItemActivity.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  24/03/2014 22:26:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

ItemActivity::ItemActivity() {
	m_itemwin = new ItemWindow();
	
	m_itemwin->addItem("Potion");
	m_itemwin->addItem("Potion");
	m_itemwin->addItem("Potion");
	m_itemwin->addItem("Potion2");
	m_itemwin->addItem("Potion2");
	m_itemwin->addItem("Potion2");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
	m_itemwin->addItem("Potion3");
}

ItemActivity::~ItemActivity() {
	delete m_itemwin;
}

void ItemActivity::update() {
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

void ItemActivity::render() {
	MenuActivity::render();
	
	m_itemwin->draw();
}
