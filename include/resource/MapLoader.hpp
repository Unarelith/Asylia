/*
 * =====================================================================================
 *
 *       Filename:  MapLoader.hpp
 *
 *    Description:
 *
 *        Created:  18/02/2019 08:39:24
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MAPLOADER_HPP_
#define MAPLOADER_HPP_

#include <gk/resource/IResourceLoader.hpp>

class MapLoader : public gk::IResourceLoader {
	public:
		void load(const char *xmlFilename, gk::ResourceHandler &handler) override;
};

#endif // MAPLOADER_HPP_
