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
		Player(const char *filename, s16 x, s16 y, u8 direction, u16 area, u16 mapX, u16 mapY);
		~Player();
		
		void move();
};

#endif // PLAYER_HPP_
