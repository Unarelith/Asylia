/*
 * =====================================================================================
 *
 *       Filename:  ArmorLoader.hpp
 *
 *    Description:
 *
 *        Created:  17/02/2019 21:50:42
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ARMORLOADER_HPP_
#define ARMORLOADER_HPP_

#include <gk/resource/IResourceLoader.hpp>

class ArmorLoader : public gk::IResourceLoader {
	public:
		void load(const char *xmlFilename, gk::ResourceHandler &handler) override;
};

#endif // ARMORLOADER_HPP_
