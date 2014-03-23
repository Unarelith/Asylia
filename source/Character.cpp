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
	m_type = Type::None;
	
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
	
	m_hitboxX = 0;
	m_hitboxY = 16;
	
	m_hitboxW = 32;
	m_hitboxH = 32;
	
	addAnimation(4, AnimationManager::character[DIR_DOWN],	125);
	addAnimation(4, AnimationManager::character[DIR_LEFT],	125);
	addAnimation(4, AnimationManager::character[DIR_RIGHT],	125);
	addAnimation(4, AnimationManager::character[DIR_UP],	125);
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

void Character::move(std::string moveScript) {
	if(m_vxCount == 0 && m_vyCount == 0) {
		LuaHandler::doFile(moveScript.c_str());
	}
	
	if(m_vx > 0) m_direction = DIR_RIGHT;
	if(m_vx < 0) m_direction = DIR_LEFT;
	if(m_vy > 0) m_direction = DIR_DOWN;
	if(m_vy < 0) m_direction = DIR_UP;
	
	testCollisions();
	
	m_vxCount += abs(m_vx);
	m_vyCount += abs(m_vy);
	
	m_x += m_vx;
	m_y += m_vy;
	
	if(m_vxCount >= 32 || m_vyCount >= 32) {
		m_vxCount = 0;
		m_vyCount = 0;
		
		m_moving = false;
		
		m_vx = 0;
		m_vy = 0;
	}
}

void Character::testCollisions() {
	mapCollisions();
}

void Character::mapCollisions() {
	if((!passable(m_x + m_hitboxX + m_vx,
				  m_y + m_hitboxY))
	|| (!passable(m_x + m_hitboxX + m_hitboxW - 1 + m_vx,
				  m_y + m_hitboxY))
	|| (!passable(m_x + m_hitboxX + m_vx,
				  m_y + m_hitboxY + m_hitboxH - 1))
	|| (!passable(m_x + m_hitboxX + m_hitboxW - 1 + m_vx,
				  m_y + m_hitboxY + m_hitboxH - 1))) {
		m_vx = 0;
		m_vxCount = 32;
		collisionAction(NULL);
	}
	
	if((!passable(m_x + m_hitboxX,
				  m_y + m_hitboxY + m_vy))
	|| (!passable(m_x + m_hitboxX,
				  m_y + m_hitboxY + m_hitboxH - 1 + m_vy))
	|| (!passable(m_x + m_hitboxX + m_hitboxW - 1,
				  m_y + m_hitboxY + m_vy))
	|| (!passable(m_x + m_hitboxX + m_hitboxW - 1,
				  m_y + m_hitboxY + m_hitboxH - 1 + m_vy))) {
		m_vy = 0;
		m_vyCount = 32;
		collisionAction(NULL);
	}
}

void Character::inCollisionWith(Character *c) {
	if(m_vx != 0
	&& m_x + m_hitboxX + m_vx < c->m_x + c->m_hitboxX + c->m_hitboxW
	&& m_x + m_hitboxX + m_vx + m_hitboxW > c->m_x + c->m_hitboxX
	&& m_y + m_hitboxY < c->m_y + c->m_hitboxY + c->m_hitboxH
	&& m_y + m_hitboxY + m_hitboxH > c->m_y + c->m_hitboxY) {
		m_vx = 0;
		
		collisionAction(c);
	}
	
	if(m_vy != 0
	&& m_x + m_hitboxX < c->m_x + c->m_hitboxX + c->m_hitboxW
	&& m_x + m_hitboxX + m_hitboxW > c->m_x + c->m_hitboxX
	&& m_y + m_hitboxY + m_vy < c->m_y + c->m_hitboxY + c->m_hitboxH
	&& m_y + m_hitboxY + m_vy + m_hitboxH > c->m_y + c->m_hitboxY) {
		m_vy = 0;
		
		collisionAction(c);
	}
}

void Character::eventCollisions() {
	
}

void Character::collisionAction(Character *c) {
	m_moving = false;
	if(c && c->m_type == Type::Event) c->exec();
}

