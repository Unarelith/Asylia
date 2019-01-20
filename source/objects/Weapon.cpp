/*
 * =====================================================================================
 *
 *       Filename:  Weapon.cpp
 *
 *    Description:
 *
 *        Created:  06/04/2014 23:59:34
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Weapon::Weapon(std::string name, std::string description, std::string thumbnail, u16 atk, double hitRate) : Item(name, description, thumbnail) {
	m_type = Type::Weapon;

	m_atk = atk;
	m_hitRate = hitRate;

	// FIXME: Temporary
	m_equipType = 0;
}

Weapon::~Weapon() {
}

