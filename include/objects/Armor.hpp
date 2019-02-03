/*
 * =====================================================================================
 *
 *       Filename:  Armor.hpp
 *
 *    Description:
 *
 *        Created:  06/04/2014 23:49:25
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ARMOR_HPP_
#define ARMOR_HPP_

#include "Item.hpp"

/* SLOTS *\
 0: Shield
 1: Head
 2: Body
\*       */

class Armor : public Item {
	public:
		Armor(std::string name, std::string description, std::string thumbnail, u8 slot, u16 def);

		u8 slot() const { return m_slot; }
		u16 def() const { return m_def; }

	private:
		u8 m_slot;
		u16 m_def;
};

#endif // ARMOR_HPP_
