/*
 * =====================================================================================
 *
 *       Filename:  Weapon.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/04/2014 23:56:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef WEAPON_HPP_
#define WEAPON_HPP_

class Weapon : public Item {
	public:
		Weapon(std::string name, std::string description, u8 level, std::string thumbnail, u16 damage, double hitRate);
		~Weapon();
		
		u16 damage() const { return m_damage; }
		double hitRate() const { return m_hitRate; }
		
		static u16 count;
		
	private:
		u16 m_damage;
		double m_hitRate;
};

#endif // WEAPON_HPP_
