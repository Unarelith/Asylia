/*
 * =====================================================================================
 *
 *       Filename:  QuestLoader.hpp
 *
 *    Description:
 *
 *        Created:  17/02/2019 22:38:03
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef QUESTLOADER_HPP_
#define QUESTLOADER_HPP_

#include <gk/resource/IResourceLoader.hpp>

class QuestLoader : public gk::IResourceLoader {
	public:
		void load(const char *xmlFilename, gk::ResourceHandler &handler) override;
};

#endif // QUESTLOADER_HPP_
