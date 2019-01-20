/*
 * =====================================================================================
 *
 *       Filename:  Equipment.hpp
 *
 *    Description:
 *
 *        Created:  10/06/2014 22:14:14
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef EQUIPMENT_HPP_
#define EQUIPMENT_HPP_

class Equipment {
	public:
		Equipment();
		~Equipment();

		void equipWeapon(Weapon *weapon) { m_weapon = weapon; m_weapon->setEquipped(true); }
		void equipArmor(Armor *armor);

		void unequipWeapon() { m_weapon->setEquipped(false); m_weapon = NULL; }
		void unequipArmor(u8 slot);

		Weapon *weapon() const { return m_weapon; }
		Armor *armor(u8 slot) const { for(auto it : m_armors) if(it->slot() == slot) return it; return NULL; }
		std::list<Armor*> armors() const { return m_armors; }

	private:
		Weapon *m_weapon;
		std::list<Armor*> m_armors;
};

#endif // EQUIPMENT_HPP_
