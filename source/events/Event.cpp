/*
 * =====================================================================================
 *
 *       Filename:  Event.cpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 23:54:51
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Event.hpp"
#include "EventInterpreter.hpp"
#include "LuaHandler.hpp"
#include "SpriteAnimationManager.hpp"
#include "StateManager.hpp"

Event::Event(const std::string &name, const std::string &appearance, u16 x, u16 y, u8 anim, bool solid, u16 frameWidth, u16 frameHeight) : Character(appearance.c_str(), x, y, anim, frameWidth, frameHeight) {
	if(appearance.find("event") != std::string::npos) {
		m_type = Type::TypeEvent;

		addAnimation(SpriteAnimationManager::spriteAnimations["Event"][DIR_DOWN]);
		addAnimation(SpriteAnimationManager::spriteAnimations["Event"][DIR_LEFT]);
		addAnimation(SpriteAnimationManager::spriteAnimations["Event"][DIR_RIGHT]);
		addAnimation(SpriteAnimationManager::spriteAnimations["Event"][DIR_UP]);
	} else {
		if(appearance == "") m_type = Type::TypeEvent;
		else m_type = Type::TypeNPC;

		addAnimation(SpriteAnimationManager::spriteAnimations["Character"][DIR_DOWN]);
		addAnimation(SpriteAnimationManager::spriteAnimations["Character"][DIR_LEFT]);
		addAnimation(SpriteAnimationManager::spriteAnimations["Character"][DIR_RIGHT]);
		addAnimation(SpriteAnimationManager::spriteAnimations["Character"][DIR_UP]);
	}

	m_folder = std::string("data/events/") + name + "/";
	m_name = name;

	m_solid = solid;
}

void Event::init() {
	LuaHandler::doFile((m_folder + "main.lua").c_str());
	LuaHandler::doString(m_name + ".init()");
}

void Event::move(std::string function) {
	LuaHandler::doString(function);

	Character::move();
}

void Event::update() {
	updateActions();

	if(StateManager::top()->type() == ApplicationState::Type::Map) {
		move(m_name + ".movements[" + std::to_string(m_movementID) + " % #" + m_name + ".movements + 1](" + std::to_string(m_speed) + ")");
	}

	LuaHandler::doString(m_name + ".update()");
}

void Event::updateActions() {
	EventInterpreter::update(this);
}

void Event::render() {
	LuaHandler::doString(m_name + ".render()");
}

void Event::collisionAction(Character *character) {
	Character::collisionAction(character);
	// FIXME: Doesn't work
	if (character)
		LuaHandler::doString(m_name + ".collisionAction()");
}

