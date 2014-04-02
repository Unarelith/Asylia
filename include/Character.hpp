/*
 * =====================================================================================
 *
 *       Filename:  Character.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 19:27:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#define DIR_DOWN 0
#define DIR_LEFT 1
#define DIR_RIGHT 2
#define DIR_UP 3

class Event;

class Character : public Sprite {
	public:
		Character(const char *filename, s16 x, s16 y, u8 direction, u16 area, u16 mapX, u16 mapY, u16 frameWidth = 32, u16 frameHeight = 48);
		virtual ~Character();
		
		void move(std::string function);
		void render();
		
		virtual void action() = 0;
		virtual void collisionAction() = 0;
		
		void testCollisions();
		
		void mapCollisions();
		
		void inCollisionWith(Character *c);
		bool canInitiateConversationWith(Character *c);
		void eventCollisions();
		
		void collisionAction(Character *c);
		
		void doMovement(s8 vx, s8 vy);
		void moveUp() { doMovement(0, -m_speed); }
		void moveDown() { doMovement(0, m_speed); }
		void moveLeft() { doMovement(-m_speed, 0); }
		void moveRight() { doMovement(m_speed, 0); }
		
		void changeMap(u16 area, u16 mapX, u16 mapY, u16 x, u16 y, u8 direction);
		
		s16 x() const { return m_x; }
		s16 y() const { return m_y; }
		
		u8 getDirection() const { return m_direction; }
		void setDirection(u8 direction) { m_direction = direction; }
		
		Character *inFrontOf() const { return m_inFrontOf; }
		
		void setHitbox(s16 x, s16 y, u16 width, u16 height);
		
		enum Direction {
			Down, Right, Left, Up
		};
		
		enum Type {
			None, Player, Event
		};
		
	protected:
		Type m_type;
		
		s16 m_x;
		s16 m_y;
		
		u8 m_direction;
		
		u16 m_area;
		
		u16 m_mapX;
		u16 m_mapY;
		
		s8 m_vx;
		s8 m_vy;
		
		u8 m_vxCount;
		u8 m_vyCount;
		
		bool m_moving;
		
		u8 m_speed;
		
		Timer m_movementTimer;
		u16 m_movementDelay;
		u16 m_movementID;
		
		s16 m_hitboxX;
		s16 m_hitboxY;
		
		u16 m_hitboxW;
		u16 m_hitboxH;
		
		Character *m_inFrontOf;
		
		bool m_solid;
};

#endif // CHARACTER_HPP_
