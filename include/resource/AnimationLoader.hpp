/*
 * =====================================================================================
 *
 *       Filename:  AnimationLoader.hpp
 *
 *    Description:
 *
 *        Created:  17/02/2019 21:48:56
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ANIMATIONLOADER_HPP_
#define ANIMATIONLOADER_HPP_

#include <gk/resource/IResourceLoader.hpp>

class AnimationLoader : public gk::IResourceLoader {
	public:
		void load(const char *xmlFilename, gk::ResourceHandler &handler) override;
};

#endif // ANIMATIONLOADER_HPP_
