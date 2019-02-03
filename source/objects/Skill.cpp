/*
 * =====================================================================================
 *
 *       Filename:  Skill.cpp
 *
 *    Description:
 *
 *        Created:  04/05/2014 17:58:52
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Skill.hpp"

Skill::Skill(const std::string &name, const std::string &description, const std::string &thumbnail, Animation *battleAnimation, u16 atk, double hitRate) : Item(name, description, thumbnail, battleAnimation) {
	m_type = Type::Skill;

	m_atk = atk;
	m_hitRate = hitRate;
}

