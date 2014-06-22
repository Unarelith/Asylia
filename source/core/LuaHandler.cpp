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
														 .set("drawMessage", &ActivityManager::drawMessage)
														 .set("startBattle", &ActivityManager::startBattle);
	
	SLB::Class<CharacterManager>("CharacterManager", &slbm).set("player", &CharacterManager::getPlayer);
	
	SLB::Class<Event>("Event", &slbm).inherits<Sprite>()
									 .set("moveUp", &Character::moveUp)
									 .set("moveDown", &Character::moveDown)
									 .set("moveLeft", &Character::moveLeft)
									 .set("moveRight", &Character::moveRight)
									 .set("setDirection", &Character::setDirection)
									 .set("getDirection", &Character::getDirection)
									 .set("getTicks", &SDL_GetTicks)
									 .set("render", &Character::render)
									 .set("x", &Character::x)
									 .set("y", &Character::y)
									 .set("setHitbox", &Character::setHitbox)
									 .set("setPosition", &Character::setPosition)
									 .set("name", &Event::name)
									 .set("face", &Character::face);
	
	SLB::Class<EventInterpreter>("EventInterpreter", &slbm).set("addActionToQueue", &EventInterpreter::addActionToQueue);
	
	SLB::Class<Image>("Image", &slbm).constructor<const char*>()
									 .set("renderCopy", &Image::renderCopy)
									 .set("render", &Image::render);
	
	SLB::Class<Inventory>("Inventory", &slbm).set("addItem", &Inventory::addItem);
	
	SLB::Class<Item>("Item", &slbm).set("name", &Item::name);
	
	SLB::Class<ItemManager>("ItemManager", &slbm).set("getItem", &ItemManager::getItem);
	
	SLB::Class<Keyboard>("Keyboard", &slbm).set("isKeyPressed", &Keyboard::isKeyPressed)
										   .set("isKeyPressedWithDelay", &Keyboard::isKeyPressedWithDelay)
										   .set("isKeyPressedOnce", &Keyboard::isKeyPressedOnce)
										   .set("GameUp", Keyboard::GameUp)
										   .set("GameDown", Keyboard::GameDown)
										   .set("GameLeft", Keyboard::GameLeft)
										   .set("GameRight", Keyboard::GameRight)
										   .set("GameAttack", Keyboard::GameAttack)
										   .set("GameBack", Keyboard::GameBack)
										   .set("GameMenu", Keyboard::GameMenu);
	
	SLB::Class<Map>("Map", &slbm).set("getEvent", &Map::getEvent)
								 .set("scrollX", &Map::getScrollX)
								 .set("scrollY", &Map::getScrollY);
	
	SLB::Class<BattleActivity>("BattleActivity", &slbm);
	
	SLB::Class<MapActivity>("MapActivity", &slbm);
	
	SLB::Class<MapManager>("MapManager", &slbm).set("currentMap", MapManager::currentMap);
	
	SLB::Class<MessageActivity>("MessageActivity", &slbm).set("addCommand", &MessageActivity::addCommand)
														 .set("getCmdwinPos", &MessageActivity::getCmdwinPos);
	
	SLB::Class<ParameterList>("ParameterList", &slbm).constructor()
													 .set("addIntParameter", &ParameterList::addIntParameter)
													 .set("addBoolParameter", &ParameterList::addBoolParameter)
													 .set("addFloatParameter", &ParameterList::addFloatParameter)
													 .set("addStringParameter", &ParameterList::addStringParameter)
													 .set("clear", &ParameterList::clear);
	
	SLB::Class<IntParameter>("IntParameter", &slbm);
	SLB::Class<FloatParameter>("FloatParameter", &slbm);
	SLB::Class<StringParameter>("StringParameter", &slbm);
	
	SLB::Class<Player>("Player", &slbm).set("setDirection", &Character::setDirection)
									   .set("getDirection", &Character::getDirection)
									   .set("changeMap", &Character::changeMap)
									   .set("stop", &Character::stop)
									   .set("inventory", &Player::inventory)
									   .set("x", &Character::x)
									   .set("y", &Character::y)
									   .set("inFrontOf", &Character::inFrontOf);
	
	SLB::Class<Sprite>("Sprite", &slbm).constructor<const char *, u16, u16>()
									   .set("drawFrame", &Sprite::drawFrame)
									   .set("playAnimation", &Sprite::playAnimation)
									   .set("animationAtEnd", &Sprite::animationAtEnd);
	
	SLB::Class<LanguageManager>("LanguageManager", &slbm).set("translate", &LanguageManager::translate);
	doString("function _t(str) return LanguageManager.translate(str) end");
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

