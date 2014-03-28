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
	m_y = y + 16;
	
	m_direction = direction;
	
	m_area = area;
	
	m_mapX = mapX;
	m_mapY = mapY;
	
	m_vx = 0;
	m_vy = 0;
	
	m_vxCount = 0;
	m_vyCount = 0;
	
	m_moving = false;
	
	m_speed = 1;
	
	m_movementTimer.start();
	m_movementDelay = 4000;
	m_movementID = 1;
	
	m_hitboxX = 0;
	m_hitboxY = 16;
	
	m_hitboxW = 32;
	m_hitboxH = 32;
	
	m_inFrontOf = NULL;
	
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

void Character::move(std::string function) {
	LuaHandler::doString(function);
	
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
	eventCollisions();
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
	s16 cx = (c->m_x + c->m_hitboxX) / (MapManager::currentMap->tileset()->tileWidth * 2);
	s16 cy = (c->m_y + c->m_hitboxY) / (MapManager::currentMap->tileset()->tileHeight * 2);
	
	s16 cx2 = (c->m_x + c->m_hitboxX + c->m_hitboxW - 1) / (MapManager::currentMap->tileset()->tileWidth * 2);
	s16 cy2 = (c->m_y + c->m_hitboxY + c->m_hitboxH - 1) / (MapManager::currentMap->tileset()->tileHeight * 2);
	
	s16 x, y, x2, y2;
	
	if(m_vx) {
		x = (m_x + m_vx + m_hitboxX) / (MapManager::currentMap->tileset()->tileWidth * 2);
		y = (m_y + m_hitboxY) / (MapManager::currentMap->tileset()->tileHeight * 2);
		
		x2 = (m_x + m_vx + m_hitboxX + m_hitboxW - 1) / (MapManager::currentMap->tileset()->tileWidth * 2);
		y2 = (m_y + m_hitboxY + m_hitboxH - 1) / (MapManager::currentMap->tileset()->tileHeight * 2);
		
		if(((x == cx || x == cx2) || (x2 == cx || x2 == cx2))
		&& ((y == cy || y == cy2) || (y2 == cy || y2 == cy2))) {
			m_vx = 0;
			
			debug("Collided (%d;%d) (%d;%d)", m_x + m_vx + m_hitboxX, m_y + m_hitboxY, m_vxCount, m_vyCount);
			
			collisionAction(c);
		}
	}
	
	if(m_vy) {
		x = (m_x + m_hitboxX) / (MapManager::currentMap->tileset()->tileWidth * 2);
		y = (m_y + m_vy + m_hitboxY) / (MapManager::currentMap->tileset()->tileHeight * 2);
		
		x2 = (m_x + m_hitboxX + m_hitboxW - 1) / (MapManager::currentMap->tileset()->tileWidth * 2);
		y2 = (m_y + m_vy + m_hitboxY + m_hitboxH - 1) / (MapManager::currentMap->tileset()->tileHeight * 2);
		
		if(((x == cx || x == cx2) || (x2 == cx || x2 == cx2))
		&& ((y == cy || y == cy2) || (y2 == cy || y2 == cy2))) {
			m_vy = 0;
			
			debug("Collided %d %d", m_vxCount, m_vyCount);
			
			collisionAction(c);
		}
	}
	
	if(m_vx || m_vy) {
		debug("T:%d | (%d;%d)(%d;%d) | (%d;%d)(%d;%d) || (%d;%d)", (int)m_type, x, y, x2, y2, cx, cy, cx2, cy2, m_vx, m_vy);
	}
}

bool Character::canInitiateConversationWith(Character *c) {
	s16 cx = (c->m_x + c->m_hitboxX) / (MapManager::currentMap->tileset()->tileWidth * 2);
	s16 cy = (c->m_y + c->m_hitboxY) / (MapManager::currentMap->tileset()->tileHeight * 2);
	
	s16 x = (m_x + m_hitboxX) / (MapManager::currentMap->tileset()->tileWidth * 2);
	s16 y = (m_y + m_hitboxY) / (MapManager::currentMap->tileset()->tileHeight * 2);
	
	if(cx == x) {
		if(cy == y + 1 && m_direction == DIR_DOWN) {
			return true;
		}
		if(cy == y - 1 && m_direction == DIR_UP) {
			return true;
		}
	}
	
	if(cy == y) {
		if(cx == x + 1 && m_direction == DIR_RIGHT) {
			return true;
		}
		if(cx == x - 1 && m_direction == DIR_LEFT) {
			return true;
		}
	}
	
	return false;
}

void Character::eventCollisions() {
	m_inFrontOf = NULL;
	
	for(u16 i = 0 ; i < MapManager::currentMap->events().size() ; i++) {
		if(MapManager::currentMap->events()[i] != this) {
			if(canInitiateConversationWith(MapManager::currentMap->events()[i])) {
				m_inFrontOf = MapManager::currentMap->events()[i];
			}
			inCollisionWith(MapManager::currentMap->events()[i]);
		}
	}
	
	if(m_type == Type::Event) {
		inCollisionWith(CharacterManager::player);
	}
}

void Character::collisionAction(Character *c) {
	m_moving = false;
	if(c && c->m_type == Type::Event) c->collisionAction();
}

void Character::doMovement(s8 vx, s8 vy) {
	if(m_vxCount == 0 && m_vyCount == 0 && m_movementTimer.time() > m_movementDelay) {
		m_vx = vx;
		m_vy = vy;
		m_moving = true;
		
		m_movementID++;
		
		m_movementTimer.reset();
		m_movementTimer.start();
	}
}

