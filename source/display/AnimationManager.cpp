/*
 * =====================================================================================
 *
 *       Filename:  AnimationManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 19:35:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

std::vector<Animation*> AnimationManager::animations;

void AnimationManager::init() {
	XMLFile doc("data/config/animations.xml");
	
	XMLElement *animationElement = doc.FirstChildElement("animations").FirstChildElement("animation").ToElement();
	while(animationElement) {
		std::string name, filename;
		u16 delay;
		
		name = animationElement->Attribute("name");
		filename = std::string("graphics/animations/") + animationElement->Attribute("filename") + ".png";
		
		delay = animationElement->IntAttribute("delay");
		
		std::vector<u16> frames;
		XMLElement *frameElement = animationElement->FirstChildElement("frame");
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

Animation *AnimationManager::getAnimationByName(std::string name) {
	for(auto *it : animations) {
		if(it->name() == name) {
			return it;
		}
	}
	
	return NULL;
}

