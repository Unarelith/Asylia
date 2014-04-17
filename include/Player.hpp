/*
 * =====================================================================================
 *
 *       Filename:  Player.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 19:48:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef PLAYER_HPP_
#define PLAYER_HPP_

class Player : public Character {
	public:
		Player(std::string filename, s16 x, s16 y, u8 direction, u16 area, u16 mapX, u16 mapY);
		~Player();
		
		void move();
		
		void action() {}
		void collisionAction() {}
		
		std::string name() const { return m_name; }
		
		u8 level() const { return m_level; }
		
		u16 atk() const { return m_atk; }
		u16 def() const { return m_def; }
		
		u16 totalAtk();
		u16 totalDef();
		
	private:
		std::string m_name;
		
		u8 m_level;
		
		u16 m_atk;
		u16 m_def;
};

#endif // PLAYER_HPP_
