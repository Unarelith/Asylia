/*
 * =====================================================================================
 *
 *       Filename:  TilemapLoader.hpp
 *
 *    Description:
 *
 *        Created:  25/02/2019 23:12:26
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TILEMAPLOADER_HPP_
#define TILEMAPLOADER_HPP_

#include <gk/resource/IResourceLoader.hpp>

class TilemapLoader : public gk::IResourceLoader {
	public:
		void load(const char *xmlFilename, gk::ResourceHandler &handler);

	private:
		void loadMap(const std::string &name, const std::string &tilesetName, gk::ResourceHandler &handler);
};

#endif // TILEMAPLOADER_HPP_
