/*
 * =====================================================================================
 *
 *       Filename:  Weapon.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/04/2014 23:59:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

u16 Weapon::count = 0;

Weapon::Weapon(std::string name, std::string description, u8 level, std::string thumbnail, u16 atk, double hitRate) : Item(name, description, level, thumbnail) {
	m_type = Type::Weapon;
	
	m_atk = atk;
	m_hitRate = hitRate;
	
	// FIXME: Temporary
	m_equipType = 0;
}

Weapon::~Weapon() {
}

