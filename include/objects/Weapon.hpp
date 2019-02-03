/*
 * =====================================================================================
 *
 *       Filename:  Weapon.hpp
 *
 *    Description:
 *
 *        Created:  06/04/2014 23:56:20
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef WEAPON_HPP_
#define WEAPON_HPP_

#include "Item.hpp"

class Weapon : public Item {
	public:
		Weapon(const std::string &name, const std::string &description, const std::string &thumbnail, u16 atk, double hitRate);

		u16 atk() const { return m_atk; }
		double hitRate() const { return m_hitRate; }

		u8 equipType() const { return m_equipType; }

	private:
		u16 m_atk;
		double m_hitRate;
		u8 m_equipType;
};

#endif // WEAPON_HPP_
