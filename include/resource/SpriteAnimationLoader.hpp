/*
 * =====================================================================================
 *
 *       Filename:  SpriteAnimationLoader.hpp
 *
 *    Description:
 *
 *        Created:  17/02/2019 21:33:15
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SPRITEANIMATIONLOADER_HPP_
#define SPRITEANIMATIONLOADER_HPP_

#include <gk/resource/IResourceLoader.hpp>

class SpriteAnimationLoader : public gk::IResourceLoader {
	public:
		void load(const char *xmlFilename, gk::ResourceHandler &handler) override;
};

#endif // SPRITEANIMATIONLOADER_HPP_
