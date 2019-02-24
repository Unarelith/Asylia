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
#include <gk/graphics/SpriteAnimation.hpp>
#include <gk/resource/ResourceHandler.hpp>

#include "SpriteAnimationLoader.hpp"

void SpriteAnimationLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	tinyxml2::XMLElement *animationElement = doc.FirstChildElement("spriteAnimations").FirstChildElement("animation").ToElement();
	while(animationElement) {
		std::string name = animationElement->Attribute("name");
		std::vector<gk::SpriteAnimation> animation;

		tinyxml2::XMLElement *framesElement = animationElement->FirstChildElement("frames");
		while(framesElement) {
			u16 delay = framesElement->IntAttribute("delay");
			animation.emplace_back(delay);

			gk::SpriteAnimation &anim = animation.back();

			tinyxml2::XMLElement *frameElement = framesElement->FirstChildElement("frame");
			while(frameElement) {
				anim.addFrame(frameElement->IntAttribute("id"));

				frameElement = frameElement->NextSiblingElement("frame");
			}

			framesElement = framesElement->NextSiblingElement("frames");
		}

		handler.add<std::vector<gk::SpriteAnimation>>("spriteanim-" + name, animation);

		animationElement = animationElement->NextSiblingElement("animation");
	}
}

