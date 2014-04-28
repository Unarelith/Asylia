/*
 * =====================================================================================
 *
 *       Filename:  BattleActivity.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/04/2014 19:23:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

BattleActivity::BattleActivity() {
	m_type = Type::BattleAct;
	
	m_battle = BattleManager::battles[0];
	
	m_currentActor = NULL;
	m_currentPos = 0;
	
	m_mode = Mode::Choice;
	
	Sound::Music::play(Sound::Music::battle, -1);
}

BattleActivity::~BattleActivity() {
}

void BattleActivity::update() {
	if(m_mode == Mode::Choice) {
		m_battleChoicewin.update();
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
			Sound::Effect::play(Sound::Effect::confirm);
			switch(m_battleChoicewin.pos()) {
				case 0:
					m_mode = Mode::Action;
					break;
				default: break;
			}
		}
	}
	else if(m_mode == Mode::Action) {
		m_battleActionwin.update();
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
			Sound::Effect::play(Sound::Effect::confirm);
			switch(m_battleActionwin.pos()) {
				default: break;
			}
		}
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
		Sound::Effect::play(Sound::Effect::back);
		ActivityManager::pop();
		Sound::Music::halt();
		Sound::Music::play(Sound::Music::theme, -1);
	}
}

void BattleActivity::render() {
	m_battle->renderBattleback();
	
	m_actorStatswin.drawEnemies(m_battle->enemies());
	
	if(m_mode == Mode::Choice) {
		m_battleChoicewin.draw();
	}
	else if(m_mode == Mode::Action) {
		m_battleActionwin.draw(m_currentPos);
	}
	
	m_actorStatswin.drawActors(m_battle->actors());
}

