/*
 * =====================================================================================
 *
 *       Filename:  Character.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 19:45:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Character::Character(const char *filename, s16 x, s16 y, u8 direction, u16 area, u16 mapX, u16 mapY, u16 frameWidth, u16 frameHeight) : Sprite(filename, frameWidth, frameHeight) {
	m_x = x;
	m_y = y;
	
	m_direction = direction;
	
	m_area = area;
	
	m_mapX = mapX;
	m_mapY = mapY;
	
	m_vx = 0;
	m_vy = 0;
	
	m_vxCount = 0;
	m_vyCount = 0;
	
	m_moving = false;
	
	addAnimation(4, AnimationManager::character[0], 125); // Down
	addAnimation(4, AnimationManager::character[1], 125); // Right
	addAnimation(4, AnimationManager::character[2], 125); // Left
	addAnimation(4, AnimationManager::character[3], 125); // Up
}

Character::~Character() {
}

void Character::render() {
	if(m_moving && ActivityManager::activities.top()->type() == Activity::Type::Map) {
		playAnimation(m_x, m_y, m_direction);
	} else {
		drawFrame(m_x, m_y, m_animations[m_direction]->tabAnim[0]);
	}
}

