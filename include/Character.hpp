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

class Character : public Sprite {
	public:
		Character(const char *filename, s16 x, s16 y, u8 direction, u16 area, u16 mapX, u16 mapY, u16 frameWidth = 32, u16 frameHeight = 48);
		~Character();
		
		void move(std::string moveScript);
		void render();
		
		void testCollisions();
		void mapCollisions();
		void collisionAction(void *c);
		
		s16 x() const { return m_x; }
		s16 y() const { return m_y; }
		
		enum Direction {
			Down, Right, Left, Up
		};
		
	protected:
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
		
		s16 m_hitboxX;
		s16 m_hitboxY;
		
		u16 m_hitboxW;
		u16 m_hitboxH;
};

#endif // CHARACTER_HPP_
