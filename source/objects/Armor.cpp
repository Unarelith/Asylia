/*
 * =====================================================================================
 *
 *       Filename:  Armor.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/04/2014 23:54:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Armor::Armor(std::string name, std::string description, std::string thumbnail, u8 slot, u16 def) : Item(name, description, thumbnail) {
	m_type = Type::Armor;
	
	m_slot = slot;
	m_def = def;
}

Armor::~Armor() {
}

