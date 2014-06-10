/*
 * =====================================================================================
 *
 *       Filename:  Equipment.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/06/2014 22:14:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef EQUIPMENT_HPP_
#define EQUIPMENT_HPP_

class Equipment {
	public:
		Equipment();
		~Equipment();
		
		void equipWeapon(Weapon *weapon) { m_weapon = weapon; }
		void equipArmor(Armor *armor);
		
		Weapon *weapon() const { return m_weapon; }
		Armor *armor(u8 slot) const { for(auto it : m_armors) if(it->slot() == slot) return it; return NULL; }
		
	private:
		Weapon *m_weapon;
		std::list<Armor*> m_armors;
};

#endif // EQUIPMENT_HPP_
