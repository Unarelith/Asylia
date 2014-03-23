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
	SLB::Class<ActivityManager>("ActivityManager", &slbm).set("top", &ActivityManager::top)
														 .set("pop", &ActivityManager::pop)
														 .set("push", &ActivityManager::push)
														 .set("size", &ActivityManager::size)
														 .set("newDialog", &ActivityManager::newDialog);
	
	SLB::Class<CharacterManager>("CharacterManager", &slbm).set("player", CharacterManager::player);
	
	SLB::Class<Event>("Event", &slbm);
	
	SLB::Class<Image>("Image", &slbm).constructor<const char*>()
									 .set("renderCopy", &Image::renderCopy)
									 .set("render", &Image::render);
	
	SLB::Class<Keyboard>("Keyboard", &slbm).set("isKeyPressed", &Keyboard::isKeyPressed)
										   .set("isKeyPressedWithDelay", &Keyboard::isKeyPressedWithDelay)
										   .set("GameUp", Keyboard::GameUp)
										   .set("GameDown", Keyboard::GameDown)
										   .set("GameLeft", Keyboard::GameLeft)
										   .set("GameRight", Keyboard::GameRight)
										   .set("GameAttack", Keyboard::GameAttack)
										   .set("GameBack", Keyboard::GameBack)
										   .set("GameMenu", Keyboard::GameMenu);
	
	SLB::Class<Map>("Map", &slbm).set("getEvent", &Map::getEvent);
	
	SLB::Class<MapActivity>("MapActivity", &slbm);
	
	SLB::Class<MapManager>("MapManager", &slbm).set("currentMap", MapManager::currentMap);
	
	SLB::Class<TitleActivity>("TitleActivity", &slbm).constructor();
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

