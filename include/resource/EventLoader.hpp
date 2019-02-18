/*
 * =====================================================================================
 *
 *       Filename:  EventLoader.hpp
 *
 *    Description:
 *
 *        Created:  18/02/2019 08:22:41
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef EVENTLOADER_HPP_
#define EVENTLOADER_HPP_

#include <gk/resource/ResourceHandler.hpp>

class EventLoader : public gk::IResourceLoader {
	public:
		void load(const char *xmlFilename, gk::ResourceHandler &handler) override;

	private:
		void loadCharacterEvent(tinyxml2::XMLElement *characterElement, gk::ResourceHandler &handler);
		void loadChestEvent(tinyxml2::XMLElement *chestEvent, gk::ResourceHandler &handler);
};

#endif // EVENTLOADER_HPP_
