/*
 * =====================================================================================
 *
 *       Filename:  Enemy.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/04/2014 19:33:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Enemy::Enemy(std::string name, std::string appearance, u8 level) : Battler(name, appearance, level) {
	m_type = Type::TypeEnemy;
	
	m_inventory = new Inventory;
}

Enemy::~Enemy() {
	delete m_inventory;
}

