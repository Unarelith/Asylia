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
	
	m_battle = new Battle;
	
	m_battle->addActor(new Actor());
	m_battle->addActor(new Actor());
	m_battle->addActor(new Actor());
	m_battle->addActor(new Actor());
	
	m_battle->addEnemy(new Enemy());
	
	m_currentActor = NULL;
	
	m_mode = Mode::Choice;
}

BattleActivity::~BattleActivity() {
	delete m_battle;
}

void BattleActivity::update() {
	if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
		Sound::Effect::play(Sound::Effect::back);
		ActivityManager::pop();
	}
	
	if(m_mode == Mode::Choice) {
		m_battleChoicewin.update();
	}
}

void BattleActivity::render() {
	m_battle->renderBattleback();
	
	m_actorStatswin.draw(m_battle->enemies(), m_battle->actors());
	
	if(m_mode == Mode::Choice) {
		m_battleChoicewin.draw();
	}
}

