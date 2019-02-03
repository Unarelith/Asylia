/*
 * =====================================================================================
 *
 *       Filename:  Equipment.cpp
 *
 *    Description:
 *
 *        Created:  10/06/2014 22:13:46
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Equipment.hpp"

Equipment::Equipment() {
	m_weapon = nullptr;
}

void Equipment::equipArmor(Armor *armor) {
	for(auto it : m_armors) {
		if(it->slot() == armor->slot()) {
			m_armors.remove(it);
			break;
		}
	}

	m_armors.push_back(armor);
	m_armors.back()->setEquipped(true);
}

void Equipment::unequipArmor(u8 slot) {
	for(auto it : m_armors) {
		if(it->slot() == slot) {
			it->setEquipped(false);
			m_armors.remove(it);
			break;
		}
	}
}

