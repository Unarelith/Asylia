/*
 * =====================================================================================
 *
 *       Filename:  SpriteAnimationManager.cpp
 *
 *    Description:
 *
 *        Created:  26/05/2014 19:06:52
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

std::map<std::string, std::vector<SpriteAnimation>> SpriteAnimationManager::spriteAnimations;

void SpriteAnimationManager::init() {
	XMLFile doc("data/config/spriteAnimations.xml");

	XMLElement *animationElement = doc.FirstChildElement("spriteAnimations").FirstChildElement("animation").ToElement();
	while(animationElement) {
		std::string name = animationElement->Attribute("name");
		std::vector<SpriteAnimation> animation;

		XMLElement *framesElement = animationElement->FirstChildElement("frames");
		while(framesElement) {
			std::vector<u16> frames;
			u16 delay = framesElement->IntAttribute("delay");

			XMLElement *frameElement = framesElement->FirstChildElement("frame");
			while(frameElement) {
				frames.push_back(frameElement->IntAttribute("id"));

				frameElement = frameElement->NextSiblingElement("frame");
			}

			animation.push_back(SpriteAnimation(frames.size(), frames, delay));

			framesElement = framesElement->NextSiblingElement("frames");
		}

		spriteAnimations[name] = animation;

		animationElement = animationElement->NextSiblingElement("animation");
	}
}

void SpriteAnimationManager::free() {
	for(auto &it : spriteAnimations) {
		it.second.clear();
	}
	spriteAnimations.clear();
}

