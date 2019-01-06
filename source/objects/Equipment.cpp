/*
 * =====================================================================================
 *
 *       Filename:  Equipment.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/06/2014 22:13:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Equipment::Equipment() {
	m_weapon = NULL;
}

Equipment::~Equipment() {
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

