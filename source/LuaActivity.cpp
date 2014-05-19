/*
 * =====================================================================================
 *
 *       Filename:  LuaActivity.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/03/2014 18:23:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

LuaActivity::LuaActivity(std::string filename, std::string table) {
	m_type = Type::Lua;
	
	m_table = table;
	
	LuaHandler::doFile(filename.c_str());
	LuaHandler::doString(table + ".init()");
}

LuaActivity::~LuaActivity() {
}

void LuaActivity::update() {
	MapActivity::update();
	
	LuaHandler::doString(m_table + ".update()");
}

void LuaActivity::render() {
	MapActivity::render();
	
	LuaHandler::doString(m_table + ".render()");
}

