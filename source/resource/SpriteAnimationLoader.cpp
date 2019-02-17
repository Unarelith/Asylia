/*
 * =====================================================================================
 *
 *       Filename:  SpriteAnimationLoader.cpp
 *
 *    Description:
 *
 *        Created:  17/02/2019 21:34:14
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/resource/ResourceHandler.hpp>

#include "SpriteAnimation.hpp"
#include "SpriteAnimationLoader.hpp"

void SpriteAnimationLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	tinyxml2::XMLElement *animationElement = doc.FirstChildElement("spriteAnimations").FirstChildElement("animation").ToElement();
	while(animationElement) {
		std::string name = animationElement->Attribute("name");
		std::vector<SpriteAnimation> animation;

		tinyxml2::XMLElement *framesElement = animationElement->FirstChildElement("frames");
		while(framesElement) {
			std::vector<u16> frames;
			u16 delay = framesElement->IntAttribute("delay");

			tinyxml2::XMLElement *frameElement = framesElement->FirstChildElement("frame");
			while(frameElement) {
				frames.push_back(frameElement->IntAttribute("id"));

				frameElement = frameElement->NextSiblingElement("frame");
			}

			animation.push_back(SpriteAnimation(frames.size(), frames, delay));

			framesElement = framesElement->NextSiblingElement("frames");
		}

		handler.add<std::vector<SpriteAnimation>>("spriteanim-" + name, animation);

		animationElement = animationElement->NextSiblingElement("animation");
	}
}

