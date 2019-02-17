/*
 * =====================================================================================
 *
 *       Filename:  TroopLoader.hpp
 *
 *    Description:
 *
 *        Created:  17/02/2019 20:57:42
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TROOPLOADER_HPP_
#define TROOPLOADER_HPP_

#include <gk/resource/IResourceLoader.hpp>

class TroopLoader : public gk::IResourceLoader {
	public:
		void load(const char *xmlFilename, gk::ResourceHandler &handler) override;
};

#endif // TROOPLOADER_HPP_
