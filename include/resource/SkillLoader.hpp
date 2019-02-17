/*
 * =====================================================================================
 *
 *       Filename:  SkillLoader.hpp
 *
 *    Description:
 *
 *        Created:  17/02/2019 21:51:22
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SKILLLOADER_HPP_
#define SKILLLOADER_HPP_

#include <gk/resource/IResourceLoader.hpp>

class SkillLoader : public gk::IResourceLoader {
	public:
		void load(const char *xmlFilename, gk::ResourceHandler &handler) override;
};

#endif // SKILLLOADER_HPP_
