/*
 * =====================================================================================
 *
 *       Filename:  LuaHandler.hpp
 *
 *    Description:
 *
 *        Created:  21/03/2014 23:46:58
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef LUAHANDLER_HPP_
#define LUAHANDLER_HPP_

#include <string>

// #include "SLB.hpp"

namespace LuaHandler {
	void init();
	void free();

	void bindClasses();

	void doFile(const char *filename);
	void doString(const std::string &str);

	// extern lua_State *L;
	// extern SLB::Manager slbm;
};

#endif // LUAHANDLER_HPP_
