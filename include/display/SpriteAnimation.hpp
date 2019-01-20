/*
 * =====================================================================================
 *
 *       Filename:  SpriteAnimation.hpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 19:33:35
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
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
