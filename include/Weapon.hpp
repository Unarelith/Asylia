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
		Weapon(std::string name, std::string description, u8 level, std::string thumbnail, u16 atk, double hitRate);
		~Weapon();
		
		u16 atk() const { return m_atk; }
		double hitRate() const { return m_hitRate; }
		
		u8 equipType() const { return m_equipType; }
		
		static u16 count;
		
	private:
		u16 m_atk;
		double m_hitRate;
		u8 m_equipType;
};

#endif // WEAPON_HPP_
