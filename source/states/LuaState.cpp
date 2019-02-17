/*
 * =====================================================================================
 *
 *       Filename:  LuaState.cpp
 *
 *    Description:
 *
 *        Created:  21/03/2014 18:23:52
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "GameWindow.hpp"
#include "LuaState.hpp"
#include "LuaHandler.hpp"

LuaState::LuaState(const std::string &filename, const std::string &table) {
	m_table = table;

	LuaHandler::getInstance().doFile(filename.c_str());
	LuaHandler::getInstance().doString(table + ".init()");
}

void LuaState::update() {
	LuaHandler::getInstance().doString(m_table + ".update()");
}

void LuaState::render() {
	if (m_parent)
		m_parent->render();

	LuaHandler::getInstance().doString(m_table + ".render()");
}

