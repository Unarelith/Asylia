/*
 * =====================================================================================
 *
 *       Filename:  AnimationLoader.cpp
 *
 *    Description:
 *
 *        Created:  17/02/2019 21:49:41
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/resource/ResourceHandler.hpp>

#include "Animation.hpp"
#include "AnimationLoader.hpp"

void AnimationLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	tinyxml2::XMLElement *animationElement = doc.FirstChildElement("animations").FirstChildElement("animation").ToElement();
	while(animationElement) {
		std::string name, filename;
		u16 delay;

		name = animationElement->Attribute("name");
		filename = std::string("resources/graphics/animations/") + animationElement->Attribute("filename") + ".png";

		delay = animationElement->IntAttribute("delay");

		std::vector<u16> frames;
		tinyxml2::XMLElement *frameElement = animationElement->FirstChildElement("frame");
		while(frameElement) {
			frames.push_back(frameElement->IntAttribute("id"));

			frameElement = frameElement->NextSiblingElement("frame");
		}

		handler.add<Animation>("animation-" + name, filename.c_str(), name, delay, frames);

		animationElement = animationElement->NextSiblingElement("animation");
	}
}

