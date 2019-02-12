/*
 * =====================================================================================
 *
 *       Filename:  SpriteAnimationManager.hpp
 *
 *    Description:
 *
 *        Created:  26/05/2014 19:06:52
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SPRITEANIMATIONMANAGER_HPP_
#define SPRITEANIMATIONMANAGER_HPP_

#include <map>

#include "Singleton.hpp"
#include "SpriteAnimation.hpp"

class SpriteAnimationManager : public Singleton<SpriteAnimationManager> {
	public:
		void init();

		SpriteAnimation &getAnimation(const std::string &name, size_t id) { return m_spriteAnimations[name][id]; }

	private:
		std::map<std::string, std::vector<SpriteAnimation>> m_spriteAnimations;
};

#endif // SPRITEANIMATIONMANAGER_HPP_
