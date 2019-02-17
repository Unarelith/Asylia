/*
 * =====================================================================================
 *
 *       Filename:  EnemyLoader.hpp
 *
 *    Description:
 *
 *        Created:  17/02/2019 21:02:15
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ENEMYLOADER_HPP_
#define ENEMYLOADER_HPP_

#include <gk/resource/IResourceLoader.hpp>

class EnemyLoader : public gk::IResourceLoader {
	public:
		void load(const char *xmlFilename, gk::ResourceHandler &handler) override;
};

#endif // ENEMYLOADER_HPP_
