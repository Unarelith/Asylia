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

Actor::Actor(std::string name, std::string appearance, u8 level, s16 hp, s16 sp, u16 atk, u16 def) : Battler(name, appearance, level, hp, sp, atk, def) {
	m_type = Type::TypeActor;
}

Actor::~Actor() {
}

