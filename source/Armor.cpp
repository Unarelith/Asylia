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

u16 Armor::count = 0;

Armor::Armor(std::string name, std::string description, u8 level, std::string thumbnail, u8 slot, u16 defense) : Item(name, description, level, thumbnail) {
	m_slot = slot;
	m_defense = defense;
}

Armor::~Armor() {
}

