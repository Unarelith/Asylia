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

Enemy::Enemy() : Battler() {
	m_image = new Image("graphics/battlers/Undead01.png");
}

Enemy::~Enemy() {
}

