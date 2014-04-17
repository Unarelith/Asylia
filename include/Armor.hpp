/*
 * =====================================================================================
 *
 *       Filename:  Armor.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/04/2014 23:49:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef ARMOR_HPP_
#define ARMOR_HPP_

/* SLOTS *\
 0: Shield
 1: Head
 2: Body
\*       */

class Armor : public Item {
	public:
		Armor(std::string name, std::string description, u8 level, std::string thumbnail, u8 slot, u16 def);
		~Armor();
		
		u8 slot() const { return m_slot; }
		u16 def() const { return m_def; }
		
		static u16 count;
		
	private:
		u8 m_slot;
		u16 m_def;
};

#endif // ARMOR_HPP_
