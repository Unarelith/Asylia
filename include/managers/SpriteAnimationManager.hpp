/*
 * =====================================================================================
 *
 *       Filename:  SpriteAnimationManager.hpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  26/05/2014 19:06:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
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
