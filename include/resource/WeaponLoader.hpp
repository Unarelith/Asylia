/*
 * =====================================================================================
 *
 *       Filename:  WeaponLoader.hpp
 *
 *    Description:
 *
 *        Created:  17/02/2019 21:51:04
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef WEAPONLOADER_HPP_
#define WEAPONLOADER_HPP_

#include <gk/resource/IResourceLoader.hpp>

class WeaponLoader : public gk::IResourceLoader {
	public:
		void load(const char *xmlFilename, gk::ResourceHandler &handler) override;
};

#endif // WEAPONLOADER_HPP_
