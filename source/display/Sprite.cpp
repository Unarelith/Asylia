/*
 * =====================================================================================
 *
 *       Filename:  Sprite.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 19:39:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Sprite::Sprite(const char *filename, u16 frameWidth, u16 frameHeight) : Image(filename) {
	m_frameWidth = frameWidth;
	m_frameHeight = frameHeight;
	
	m_lastFrameDisplayed = 0;
}

Sprite::~Sprite() {
}

void Sprite::reload(Sprite *sprite) {
	Image::reload(sprite->m_filename.c_str());
	
	m_animations.clear();
	
	m_lastFrameDisplayed = 0;
}

void Sprite::drawFrame(s16 x, s16 y, u16 frame) {
	u16 frameY = (frame / (m_width / m_frameWidth)) * m_frameHeight;
	u16 frameX = (frame - (frameY / m_frameHeight) * (m_width / m_frameWidth)) * m_frameWidth;
	
	m_lastFrameDisplayed = frame;
	
	render(x, y, m_frameWidth, m_frameHeight, frameX, frameY, m_frameWidth, m_frameHeight);
}

void Sprite::addAnimation(SpriteAnimation animation) {
	m_animations.push_back(SpriteAnimation(animation.size, animation.tabAnim, animation.delay));
}

void Sprite::resetAnimation(u16 anim) {
	m_animations[anim].timer.reset();
	m_animations[anim].isPlaying = false;
}

void Sprite::startAnimation(u16 anim) {
	m_animations[anim].timer.start();
	m_animations[anim].isPlaying = true;
}

void Sprite::stopAnimation(u16 anim) {
	m_animations[anim].timer.stop();
	m_animations[anim].isPlaying = false;
}

bool Sprite::animationAtEnd(u16 anim) {
	return m_animations[anim].timer.time() / m_animations[anim].delay >= m_animations[anim].size;
}

bool Sprite::animationAtFrame(u16 anim, u16 frame) {
	return (u16)(m_animations[anim].timer.time() / m_animations[anim].delay) == frame;
}

void Sprite::playAnimation(s16 x, s16 y, u16 anim) {
	if(!m_animations[anim].isPlaying) {
		resetAnimation(anim);
		startAnimation(anim);
		m_animations[anim].isPlaying = true;
	}
	
	if(animationAtEnd(anim)) {
		resetAnimation(anim);
		startAnimation(anim);
	}
	
	u16 animToDraw = m_animations[anim].tabAnim[(u16)(m_animations[anim].timer.time() / m_animations[anim].delay)];
	drawFrame(x, y, animToDraw);
}

