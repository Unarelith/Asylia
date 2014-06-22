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

EquipActivity::EquipActivity(u8 actorPos, Activity *parent) : Activity(parent) {
	m_type = Type::Equip;
	
	m_itemMode = false;
	
	m_actor = CharacterManager::player->getTeamMember(actorPos);
	
	m_equipment = CharacterManager::player->getTeamMember(actorPos)->equipment();
	
	m_statswin = new EquipStatsWindow(m_actor);
	m_choicewin = new EquipChoiceWindow(m_equipment);
	
	m_itemwin = new ItemWindow(150, 52 + (GameWindow::main->height() - 52) / 2, GameWindow::main->width() - 150, (GameWindow::main->height() - 52) / 2, CharacterManager::player->inventory(), 150, 0);
	m_itemwin->changeSet(0, 0, m_equipment);
}

EquipActivity::~EquipActivity() {
	delete m_itemwin;
	
	delete m_choicewin;
	delete m_statswin;
}

void EquipActivity::update() {
	// FIXME: SLOW?? //
	if(m_choicewin->pos() == 0) {
		m_itemwin->changeSet(m_choicewin->pos(), m_choicewin->pos(), m_equipment);
	} else {
		m_itemwin->changeSet(m_choicewin->pos(), m_choicewin->pos() - 1, m_equipment);
	}
	
	if(m_itemMode) m_itemwin->update();
	else m_choicewin->update();
	
	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		if(m_itemMode) {
			Sound::Effect::play(Sound::Effect::confirm);
			
			Item *currentItem = m_itemwin->currentItem();
			if(m_choicewin->pos() == 0) {
				if(currentItem) m_equipment->equipWeapon((Weapon*)currentItem);
				else m_equipment->unequipWeapon();
			} else {
				if(currentItem) m_equipment->equipArmor((Armor*)currentItem);
				else m_equipment->unequipArmor(m_choicewin->pos() - 1);
			}
			
			m_itemMode = false;
			m_itemwin->pos(0);
			m_itemwin->update();
		}
		else if(m_itemwin->itemMax() == 0) {
			Sound::Effect::play(Sound::Effect::blocked);
		} else {
			Sound::Effect::play(Sound::Effect::confirm);
			
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
			if(ActivityManager::top()->type() == Activity::Type::Menu) ((MenuActivity*)ActivityManager::top())->actorChoiceModeOn();
		}
	}
}

void EquipActivity::render() {
	renderBackground();
	
	if(m_itemMode) m_statswin->draw(m_itemwin->currentItem());
	else m_statswin->draw();
	m_choicewin->draw(!m_itemMode);
	m_itemwin->draw(m_itemMode, m_itemMode);
}

