/*
 * =====================================================================================
 *
 *       Filename:  Skill.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/05/2014 17:58:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Skill::Skill(std::string name, std::string description, std::string thumbnail, u16 atk, double hitRate) : Item(name, description, thumbnail) {
	m_type = Type::Skill;
	
	m_atk = atk;
	m_hitRate = hitRate;
}

Skill::~Skill() {
}

