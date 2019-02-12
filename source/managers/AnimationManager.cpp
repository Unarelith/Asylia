/*
 * =====================================================================================
 *
 *       Filename:  AnimationManager.cpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 19:35:16
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "AnimationManager.hpp"
#include "XMLFile.hpp"

template<>
AnimationManager *Singleton<AnimationManager>::s_instance = nullptr;

void AnimationManager::init() {
	XMLFile doc("data/config/animations.xml");

	tinyxml2::XMLElement *animationElement = doc.FirstChildElement("animations").FirstChildElement("animation").ToElement();
	while(animationElement) {
		std::string name, filename;
		u16 delay;

		name = animationElement->Attribute("name");
		filename = std::string("graphics/animations/") + animationElement->Attribute("filename") + ".png";

		delay = animationElement->IntAttribute("delay");

		std::vector<u16> frames;
		tinyxml2::XMLElement *frameElement = animationElement->FirstChildElement("frame");
		while(frameElement) {
			frames.push_back(frameElement->IntAttribute("id"));

			frameElement = frameElement->NextSiblingElement("frame");
		}

		m_animations.emplace_back(new Animation(filename.c_str(), name, delay, frames));

		animationElement = animationElement->NextSiblingElement("animation");
	}
}

Animation *AnimationManager::getAnimationByName(const std::string &name) {
	for(auto &it : m_animations) {
		if(it->name() == name) {
			return it.get();
		}
	}

	return nullptr;
}

