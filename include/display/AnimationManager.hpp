/*
 * =====================================================================================
 *
 *       Filename:  AnimationManager.hpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 19:34:26
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ANIMATIONMANAGER_HPP_
#define ANIMATIONMANAGER_HPP_

#include <string>
#include <vector>

#include "Animation.hpp"

namespace AnimationManager {
	void init();
	void free();

	Animation *getAnimationByName(const std::string &name);

	extern std::vector<Animation*> animations;
};

#endif // ANIMATIONMANAGER_HPP_
