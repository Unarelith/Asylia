/*
 * =====================================================================================
 *
 *       Filename:  Enemy.cpp
 *
 *    Description:
 *
 *        Created:  22/04/2014 19:33:42
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Enemy.hpp"

Enemy::Enemy(const std::string &name, const std::string &appearance, u8 level) : Battler(name, appearance, level) {
	m_type = Type::TypeEnemy;
}

