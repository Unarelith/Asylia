/*
 * =====================================================================================
 *
 *       Filename:  Animation.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  24/05/2014 15:49:52
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

class Animation : public Sprite {
	public:
		Animation(const char *filename, u16 frameWidth, u16 frameHeight);
		~Animation();
		
		void play();
};

#endif // ANIMATION_HPP_
