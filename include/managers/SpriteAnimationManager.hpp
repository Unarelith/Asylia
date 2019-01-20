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

namespace SpriteAnimationManager {
	void init();
	void free();

	extern std::map<std::string, std::vector<SpriteAnimation>> spriteAnimations;
}

#endif // SPRITEANIMATIONMANAGER_HPP_
