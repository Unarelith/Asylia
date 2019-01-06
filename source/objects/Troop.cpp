/*
 * =====================================================================================
 *
 *       Filename:  Troop.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  11/06/2014 15:32:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Troop::Troop(Image *battleback) {
	m_battleback = battleback;
}

Troop::~Troop() {
	if(m_battleback) delete m_battleback;

	m_enemies.clear();
}

