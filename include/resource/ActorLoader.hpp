/*
 * =====================================================================================
 *
 *       Filename:  ActorLoader.hpp
 *
 *    Description:
 *
 *        Created:  17/02/2019 20:59:38
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ACTORLOADER_HPP_
#define ACTORLOADER_HPP_

#include <gk/resource/IResourceLoader.hpp>

class ActorLoader : public gk::IResourceLoader {
	public:
		void load(const char *xmlFilename, gk::ResourceHandler &handler) override;
};

#endif // ACTORLOADER_HPP_
