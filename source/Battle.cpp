/*
 * =====================================================================================
 *
 *       Filename:  Battle.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  23/04/2014 18:05:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Battle::Battle(std::string battleback) {
	m_battleback = new Image(battleback.c_str());
}

Battle::~Battle() {
	delete m_battleback;
	
	m_enemies.clear();
	m_actors.clear();
}

