/*
 * =====================================================================================
 *
 *       Filename:  LuaHandler.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/03/2014 23:48:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

lua_State *LuaHandler::L = NULL;
SLB::Manager LuaHandler::slbm;

void LuaHandler::init() {
	L = luaL_newstate();
	
	luaL_openlibs(L);
	
	slbm.registerSLB(L);
	
	doString("SLB.using(SLB)");
}

void LuaHandler::free() {
	lua_close(L);
}

void LuaHandler::bindClasses() {
	SLB::Class<Image>("Image", &slbm).constructor<const char*>()
									 .set("renderCopy", &Image::renderCopy)
									 .set("render", &Image::render);
	
	SLB::Class<Character>("Character", &slbm).constructor<const char*, s16, s16, u8, u16, u16, u16, u16, u16>()
											 .set("move", &Character::move)
											 .set("render", &Character::render);
}

void LuaHandler::doFile(const char *filename) {
	if(luaL_dofile(L, filename)) {
		error("%s", lua_tostring(L, -1));
		lua_pop(L, 1);
		Game::quit = true;
	}
}

void LuaHandler::doString(std::string str) {
	if(luaL_dostring(L, str.c_str())) {
		error("%s", lua_tostring(L, -1));
		Game::quit = true;
	}
}

