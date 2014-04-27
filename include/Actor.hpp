/*
 * =====================================================================================
 *
 *       Filename:  Actor.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/04/2014 19:30:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef ACTOR_HPP_
#define ACTOR_HPP_

class Actor : public Battler {
	public:
		Actor(std::string name, std::string appearance, u8 level, s16 hp, s16 sp, u16 atk, u16 def);
		~Actor();
};

#endif // ACTOR_HPP_
