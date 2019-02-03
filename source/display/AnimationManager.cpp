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

std::vector<Animation*> AnimationManager::animations;

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

		animations.push_back(new Animation(filename.c_str(), name, delay, frames));

		animationElement = animationElement->NextSiblingElement("animation");
	}
}

void AnimationManager::free() {
	while(animations.size() != 0) {
		delete animations.back();
		animations.pop_back();
	}
}

Animation *AnimationManager::getAnimationByName(const std::string &name) {
	for(auto *it : animations) {
		if(it->name() == name) {
			return it;
		}
	}

	return nullptr;
}

