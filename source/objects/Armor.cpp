/*
 * =====================================================================================
 *
 *       Filename:  Armor.cpp
 *
 *    Description:
 *
 *        Created:  06/04/2014 23:54:11
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Armor.hpp"

Armor::Armor(const std::string &name, const std::string &description, const std::string &thumbnail, u8 slot, u16 def) : Item(name, description, thumbnail) {
	m_type = Type::Armor;

	m_slot = slot;
	m_def = def;
}

