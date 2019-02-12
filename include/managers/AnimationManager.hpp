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

#include <memory>
#include <string>
#include <vector>

#include "Animation.hpp"
#include "Singleton.hpp"

class AnimationManager : public Singleton<AnimationManager> {
	public:
		void init();

		Animation *getAnimationByName(const std::string &name);

	private:
		std::vector<std::unique_ptr<Animation>> m_animations;
};

#endif // ANIMATIONMANAGER_HPP_
