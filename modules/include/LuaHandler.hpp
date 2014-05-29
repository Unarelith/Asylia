/*
 * =====================================================================================
 *
 *       Filename:  LuaHandler.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/03/2014 23:46:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef LUAHANDLER_HPP_
#define LUAHANDLER_HPP_

namespace LuaHandler {
	void init();
	void free();
	
	void bindClasses();
	
	void doFile(const char *filename);
	void doString(std::string str);
	
	extern lua_State *L;
	extern SLB::Manager slbm;
};

#endif // LUAHANDLER_HPP_
