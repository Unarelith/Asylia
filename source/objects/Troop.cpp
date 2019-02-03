/*
 * =====================================================================================
 *
 *       Filename:  Troop.cpp
 *
 *    Description:
 *
 *        Created:  11/06/2014 15:32:37
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Troop.hpp"

Troop::Troop(Image *battleback) {
	m_battleback = battleback;
}

Troop::~Troop() {
	if(m_battleback) delete m_battleback;

	m_enemies.clear();
}

