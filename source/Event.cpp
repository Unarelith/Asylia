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

Event::Event(std::string folder, std::string table, std::string appearance, u16 x, u16 y, u8 anim, u16 area, u16 mapX, u16 mapY, bool solid) : Character(appearance.c_str(), x, y, anim, area, mapX, mapY) {
	if(appearance.find("event") != std::string::npos) {
		m_type = Type::Event;
	
		addAnimation(4, AnimationManager::event[DIR_DOWN], 125);
		addAnimation(4, AnimationManager::event[DIR_LEFT], 125);
		addAnimation(4, AnimationManager::event[DIR_RIGHT], 125);
		addAnimation(4, AnimationManager::event[DIR_UP], 125);
	} else {
		m_type = Type::NPC;
		
		addAnimation(4, AnimationManager::character[DIR_DOWN], 125);
		addAnimation(4, AnimationManager::character[DIR_LEFT], 125);
		addAnimation(4, AnimationManager::character[DIR_RIGHT], 125);
		addAnimation(4, AnimationManager::character[DIR_UP], 125);
	}
	
	m_folder = folder;
	m_table = table;
	
	m_solid = solid;
}

Event::~Event() {
}

void Event::init() {
	LuaHandler::doFile((m_folder + "main.lua").c_str());
	LuaHandler::doString(m_table + ".init()");
}

void Event::update() {
	move(m_table + ".movements[" + to_string(m_movementID) + " % #" + m_table + ".movements + 1](" + to_string(m_speed) + ")");
	
	LuaHandler::doString(m_table + ".update()");
	
	action();
}

void Event::render() {
	LuaHandler::doString(m_table + ".render()");
}

void Event::action() {
	if(CharacterManager::player->inFrontOf() == this) {
		LuaHandler::doString(m_table + ".action()");
	}
}

void Event::collisionAction() {
	LuaHandler::doString(m_table + ".collisionAction()");
}

