/*
 * =====================================================================================
 *
 *       Filename:  AudioLoader.hpp
 *
 *    Description:
 *
 *        Created:  24/01/2018 21:32:56
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef AUDIOLOADER_HPP_
#define AUDIOLOADER_HPP_

#include <gk/resource/IResourceLoader.hpp>

class AudioLoader : public gk::IResourceLoader {
	public:
		void load(const char *xmlFilename, gk::ResourceHandler &handler) override;
};

#endif // AUDIOLOADER_HPP_
