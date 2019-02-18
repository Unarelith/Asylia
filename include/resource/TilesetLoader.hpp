/*
 * =====================================================================================
 *
 *       Filename:  TilesetLoader.hpp
 *
 *    Description:
 *
 *        Created:  18/02/2019 08:38:09
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TILESETLOADER_HPP_
#define TILESETLOADER_HPP_

#include <gk/resource/IResourceLoader.hpp>

class Tileset;

class TilesetLoader : public gk::IResourceLoader {
	public:
		void load(const char *xmlFilename, gk::ResourceHandler &handler) override;

	private:
		void getNonPassableTiles(const char *filename, Tileset *tileset);
};

#endif // TILESETLOADER_HPP_
