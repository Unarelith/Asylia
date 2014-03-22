/*
 * =====================================================================================
 *
 *       Filename:  Animation.hpp
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
#ifndef ANIMATION_HPP_
#define ANIMATION_HPP_

struct Animation {
	Animation(u16 _size, u16 *_tabAnim, u16 _delay, bool _isPlaying = false) :
		size(_size), tabAnim(_tabAnim), delay(_delay), isPlaying(_isPlaying) {}
	
	u16 size;
	u16 *tabAnim;	// Animation table
	u16 delay;		// Delay between animations
	Timer timer;
	bool isPlaying;
};

typedef Animation Animation;

#endif // ANIMATION_HPP_
