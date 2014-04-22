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
	m_type = Type::Battle;
	
	m_enemies.push_back(new Enemy());
	
	m_actors.push_back(new Actor());
	m_actors.push_back(new Actor());
	m_actors.push_back(new Actor());
	m_actors.push_back(new Actor());
	
	m_currentActor = NULL;
	
	m_battleback = new Image("graphics/battlebacks/Grassland.jpg");
}

BattleActivity::~BattleActivity() {
	delete m_battleback;
	
	m_actors.clear();
	m_enemies.clear();
}

void BattleActivity::update() {
	if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
		Sound::Effect::play(Sound::Effect::back);
		ActivityManager::pop();
	}
}

void BattleActivity::render() {
	m_battleback->render();
	
	m_actorStatswin.draw(m_actors);
}

