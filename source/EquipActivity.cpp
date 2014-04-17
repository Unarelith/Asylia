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
	m_statswin = new EquipStatsWindow();
	m_choicewin = new EquipChoiceWindow();
	m_itemwin = new EquipItemWindow(0, 0);
	
	m_itemMode = false;
}

EquipActivity::~EquipActivity() {
	delete m_itemwin;
	delete m_choicewin;
	delete m_statswin;
}

void EquipActivity::update() {
	if(m_choicewin->pos() == 0) {
		m_itemwin->changeSet(m_choicewin->pos(), m_choicewin->pos());
	} else {
		m_itemwin->changeSet(m_choicewin->pos(), m_choicewin->pos() - 1);
	}
	
	if(m_itemMode) m_itemwin->update();
	else m_choicewin->update();
	
	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		Sound::Effect::play(Sound::Effect::confirm);
		
		if(m_itemMode) {
			switch(m_choicewin->pos()) {
				case 0:
					CharacterManager::player->inventory()->weapon((Weapon*)m_itemwin->currentItem());
					break;
				case 1:
					CharacterManager::player->inventory()->shield((Armor*)m_itemwin->currentItem());
					break;
				default: break;
			}
			m_itemMode = false;
			m_itemwin->pos(0);
			m_itemwin->update();
		} else {
			m_itemMode = true;
		}
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
		Sound::Effect::play(Sound::Effect::back);
		if(m_itemMode) {
			m_itemMode = false;
			m_itemwin->pos(0);
			m_itemwin->update();
		} else {
			ActivityManager::pop();
		}
	}
}

void EquipActivity::render() {
	MenuActivity::render();
	
	if(m_itemMode) m_statswin->draw(m_itemwin->currentItem());
	else m_statswin->draw();
	m_choicewin->draw(!m_itemMode);
	m_itemwin->draw(m_itemMode, m_itemMode);
}

