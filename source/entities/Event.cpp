/*
 * =====================================================================================
 *
 *       Filename:  Event.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 23:54:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Event::Event(std::string name, std::string appearance, u16 x, u16 y, u8 anim, bool solid, u16 frameWidth, u16 frameHeight) : Character(appearance.c_str(), x, y, anim, frameWidth, frameHeight) {
	if(appearance.find("event") != std::string::npos) {
		m_type = Type::Event;
		
		addAnimation(SpriteAnimationManager::spriteAnimations["Event"][DIR_DOWN]);
		addAnimation(SpriteAnimationManager::spriteAnimations["Event"][DIR_LEFT]);
		addAnimation(SpriteAnimationManager::spriteAnimations["Event"][DIR_RIGHT]);
		addAnimation(SpriteAnimationManager::spriteAnimations["Event"][DIR_UP]);
	} else {
		if(appearance == "") m_type = Type::Event;
		else m_type = Type::NPC;
		
		addAnimation(SpriteAnimationManager::spriteAnimations["Character"][DIR_DOWN]);
		addAnimation(SpriteAnimationManager::spriteAnimations["Character"][DIR_LEFT]);
		addAnimation(SpriteAnimationManager::spriteAnimations["Character"][DIR_RIGHT]);
		addAnimation(SpriteAnimationManager::spriteAnimations["Character"][DIR_UP]);
	}
	
	m_folder = std::string("data/events/") + name + "/";
	m_name = name;
	
	m_solid = solid;
}

Event::~Event() {
}

void Event::init() {
	LuaHandler::doFile((m_folder + "main.lua").c_str());
	LuaHandler::doString(m_name + ".init()");
}

void Event::move(std::string function) {
	LuaHandler::doString(function);
}

void Event::update() {
	move(m_name + ".movements[" + to_string(m_movementID) + " % #" + m_name + ".movements + 1](" + to_string(m_speed) + ")");
	
	LuaHandler::doString(m_name + ".update()");
	
	action();
}

void Event::render() {
	LuaHandler::doString(m_name + ".render()");
}

void Event::action() {
	if(CharacterManager::player->inFrontOf() == this) {
		LuaHandler::doString(m_name + ".action()");
	}
}

void Event::collisionAction() {
	LuaHandler::doString(m_name + ".collisionAction()");
}

