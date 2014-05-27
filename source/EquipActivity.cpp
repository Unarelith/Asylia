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

EquipActivity::EquipActivity(Activity *parent) : Activity(parent) {
	m_type = Type::Equip;
	
	m_itemwin = new ItemWindow(150, 52 + (GameWindow::main->height() - 52) / 2, GameWindow::main->width() - 150, (GameWindow::main->height() - 52) / 2, 150, 0);
	m_itemwin->changeSet(0, 0);
	
	m_itemMode = false;
}

EquipActivity::~EquipActivity() {
	delete m_itemwin;
}

void EquipActivity::update() {
	if(m_choicewin.pos() == 0) {
		m_itemwin->changeSet(m_choicewin.pos(), m_choicewin.pos());
	} else {
		m_itemwin->changeSet(m_choicewin.pos(), m_choicewin.pos() - 1);
	}
	
	if(m_itemMode) m_itemwin->update();
	else m_choicewin.update();
	
	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		if(m_itemwin->hasItems()) {
			Sound::Effect::play(Sound::Effect::confirm);
			
			if(m_itemMode) {
				if(m_choicewin.pos() == 0) {
					CharacterManager::player->inventory()->equipWeapon((Weapon*)m_itemwin->currentItem());
				} else {
					CharacterManager::player->inventory()->equipArmor((Armor*)m_itemwin->currentItem());
				}
				
				m_itemMode = false;
				m_itemwin->pos(0);
				m_itemwin->update();
			} else {
				m_itemMode = true;
			}
		} else {
			Sound::Effect::play(Sound::Effect::blocked);
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
	if(m_parent) m_parent->render();
	
	if(m_itemMode) m_statswin.draw(m_itemwin->currentItem());
	else m_statswin.draw();
	m_choicewin.draw(!m_itemMode);
	m_itemwin->draw(m_itemMode, m_itemMode);
}

