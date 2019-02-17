/*
 * =====================================================================================
 *
 *       Filename:  PlayerLoader.hpp
 *
 *    Description:
 *
 *        Created:  17/02/2019 23:26:07
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef PLAYERLOADER_HPP_
#define PLAYERLOADER_HPP_

#include <gk/resource/IResourceLoader.hpp>

class PlayerLoader : public gk::IResourceLoader {
	public:
		void load(const char *xmlFilename, gk::ResourceHandler &handler) override;
};

#endif // PLAYERLOADER_HPP_
