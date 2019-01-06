/*
 * =====================================================================================
 *
 *       Filename:  SpriteAnimation.hpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  22/03/2014 19:33:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef SPRITEANIMATION_HPP_
#define SPRITEANIMATION_HPP_

struct SpriteAnimation {
	SpriteAnimation(u16 _size, std::vector<u16> _tabAnim, u16 _delay, bool _isPlaying = false) :
		size(_size), tabAnim(_tabAnim), delay(_delay), isPlaying(_isPlaying) {}

	u16 size;
	std::vector<u16> tabAnim;
	u16 delay;
	Timer timer;
	bool isPlaying;
};

typedef SpriteAnimation SpriteAnimation;

#endif // SPRITEANIMATION_HPP_
