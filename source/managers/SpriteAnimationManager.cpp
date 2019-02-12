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
#include "SpriteAnimationManager.hpp"
#include "XMLFile.hpp"

template<>
SpriteAnimationManager *Singleton<SpriteAnimationManager>::s_instance = nullptr;

void SpriteAnimationManager::init() {
	XMLFile doc("data/config/spriteAnimations.xml");

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

		m_spriteAnimations[name] = animation;

		animationElement = animationElement->NextSiblingElement("animation");
	}
}

