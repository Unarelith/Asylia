/*
 * =====================================================================================
 *
 *       Filename:  Animation.cpp
 *
 *    Description:
 *
 *        Created:  24/05/2014 15:51:10
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Animation::Animation(const char *filename, std::string name, u16 delay, std::vector<u16> frames, u16 frameWidth, u16 frameHeight) : Sprite(filename, frameWidth, frameHeight) {
	m_name = name;

	addAnimation(SpriteAnimation(frames.size(), frames, delay));
}

Animation::~Animation() {
}

void Animation::play(Battler *target) {
	s16 tgx = target->image()->posRect().x + target->image()->width() / 2 - m_frameWidth / 2;
	s16 tgy = target->image()->posRect().y + target->image()->height() / 2 - m_frameHeight / 2;
	playAnimation(tgx, tgy, 0);
}

