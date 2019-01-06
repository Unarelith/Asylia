/*
 * =====================================================================================
 *
 *       Filename:  Actor.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  22/04/2014 19:32:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Actor::Actor(std::string name, std::string appearance, u8 level) : Battler(name, appearance, level) {
	m_type = Type::TypeActor;
}

Actor::~Actor() {
}

u16 Actor::totalAtk() {
	u16 atk = m_atk;
	if(m_equipment.weapon()) atk += m_equipment.weapon()->atk();
	return atk;
}

u16 Actor::totalDef() {
	u16 def = m_def;
	for(auto it : m_equipment.armors()) {
		def += it->def();
	}
	return def;
}

