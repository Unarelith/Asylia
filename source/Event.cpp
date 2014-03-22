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

Event::Event(std::string filename, std::string table, u16 x, u16 y, u8 anim, u16 area, u16 mapX, u16 mapY) {
	std::stringstream initCall;
	
	m_table = table;
	
	LuaHandler::doFile(filename.c_str());
	
	initCall << m_table << ".init(" << x << "," << y << "," << (int)anim << "," << area << "," << mapX << "," << mapY << ")";
	
	LuaHandler::doString(initCall.str());
}

Event::~Event() {
}

void Event::update() {
	LuaHandler::doString(m_table + ".update()");
}

void Event::render() {
	LuaHandler::doString(m_table + ".render()");
}

