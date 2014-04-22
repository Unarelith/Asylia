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
	
	m_currentActor = NULL;
}

BattleActivity::~BattleActivity() {
	m_enemies.clear();
	m_actors.clear();
}

void BattleActivity::update() {
	
}

void BattleActivity::render() {
	
}

