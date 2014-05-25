/*
 * =====================================================================================
 *
 *       Filename:  Animation.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  24/05/2014 15:51:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

u16 defaultAnimation[5] = {0, 1, 2, 3, 4};
Animation::Animation(const char *filename, u16 frameWidth, u16 frameHeight) : Sprite(filename, frameWidth, frameHeight) {
	addAnimation(5, defaultAnimation, 150);
}

Animation::~Animation() {
}

void Animation::play() {
}

