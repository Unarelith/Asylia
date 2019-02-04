/*
 * =====================================================================================
 *
 *       Filename:  LuaHandler.cpp
 *
 *    Description:
 *
 *        Created:  21/03/2014 23:48:26
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "LuaHandler.hpp"

#include "CharacterManager.hpp"
#include "Debug.hpp"
#include "Event.hpp"
#include "EventInterpreter.hpp"
#include "Game.hpp"
#include "ItemManager.hpp"
#include "Keyboard.hpp"
#include "Map.hpp"
#include "MapManager.hpp"
#include "MapState.hpp"
#include "MessageState.hpp"
#include "Parameter.hpp"
#include "Sprite.hpp"
#include "StateManager.hpp"

sol::state LuaHandler::lua;

void LuaHandler::init() {
	lua.open_libraries(
		sol::lib::base,
		sol::lib::math,
		sol::lib::table
	);
}

void LuaHandler::free() {
	lua.stack_clear();
}

void LuaHandler::bindClasses() {
	lua.new_usertype<StateManager>("StateManager",
		"top", &StateManager::top,
		"pop", &StateManager::pop,
		"push", &StateManager::push,
		"size", &StateManager::getSize,
		"drawMessage", &StateManager::drawMessage,
		"startBattle", &StateManager::startBattle
	);

	lua.new_usertype<CharacterManager>("CharacterManager",
		"player", &CharacterManager::getPlayer
	);

	lua.new_usertype<Event>("Event",
		"moveUp", &Character::moveUp,
		"moveDown", &Character::moveDown,
		"moveLeft", &Character::moveLeft,
		"moveRight", &Character::moveRight,
		"setDirection", &Character::setDirection,
		"getDirection", &Character::getDirection,
		"getTicks", &SDL_GetTicks,
		"render", &Character::render,
		"x", &Character::x,
		"y", &Character::y,
		"setHitbox", &Character::setHitbox,
		"setPosition", &Character::setPosition,
		"name", &Event::name,
		"face", &Character::face,
		sol::base_classes, sol::bases<Character, Sprite>()
	);

	lua.new_usertype<EventInterpreter>("EventInterpreter",
		"addActionToQueue", &EventInterpreter::addActionToQueue
	);

	lua.new_usertype<Image>("Image",
		sol::constructors<Image(const char*)>(),
		"renderCopy", &Image::renderCopy,
		"render", &Image::render
	);

	lua.new_usertype<Inventory>("Inventory",
		"addItem", &Inventory::addItem
	);

	lua.new_usertype<Item>("Item",
		"name", &Item::name
	);

	lua.new_usertype<ItemManager>("ItemManager",
		"getItem", &ItemManager::getItem
	);

	lua.new_usertype<Keyboard>("Keyboard",
		"isKeyPressed", &Keyboard::isKeyPressed,
		"isKeyPressedWithDelay", &Keyboard::isKeyPressedWithDelay,
		"isKeyPressedOnce", &Keyboard::isKeyPressedOnce
		// "GameUp", Keyboard::GameUp,
		// "GameDown", Keyboard::GameDown,
		// "GameLeft", Keyboard::GameLeft,
		// "GameRight", Keyboard::GameRight,
		// "GameAttack", Keyboard::GameAttack,
		// "GameBack", Keyboard::GameBack,
		// "GameMenu", Keyboard::GameMenu
	);

	doString(
		"Keyboard.GameUp     = " + std::to_string(Keyboard::GameUp) +
		"Keyboard.GameDown   = " + std::to_string(Keyboard::GameDown) +
		"Keyboard.GameLeft   = " + std::to_string(Keyboard::GameLeft) +
		"Keyboard.GameRight  = " + std::to_string(Keyboard::GameRight) +
		"Keyboard.GameAttack = " + std::to_string(Keyboard::GameAttack) +
		"Keyboard.GameBack   = " + std::to_string(Keyboard::GameBack) +
		"Keyboard.GameMenu   = " + std::to_string(Keyboard::GameMenu)
	);

	lua.new_usertype<Map>("Map",
		"getEvent", &Map::getEvent,
		"scrollX", &Map::getScrollX,
		"scrollY", &Map::getScrollY
	);

	lua.new_usertype<BattleState>("BattleState");

	lua.new_usertype<MapState>("MapState");

	lua.new_usertype<MapManager>("MapManager",
		// "currentMap", sol::as_function(&MapManager::currentMap)
		"currentMap", &MapManager::getCurrentMap
	);

	lua.new_usertype<MessageState>("MessageState",
		"addCommand", &MessageState::addCommand,
		"getCmdwinPos", &MessageState::getCmdwinPos
	);

	lua.new_usertype<ParameterList>("ParameterList",
		"addIntParameter", &ParameterList::addIntParameter,
		"addBoolParameter", &ParameterList::addBoolParameter,
		"addFloatParameter", &ParameterList::addFloatParameter,
		"addStringParameter", &ParameterList::addStringParameter,
		"clear", &ParameterList::clear
	);

	lua.new_usertype<IntParameter>("IntParameter");
	lua.new_usertype<FloatParameter>("FloatParameter");
	lua.new_usertype<StringParameter>("StringParameter");

	lua.new_usertype<Player>("Player",
		"setDirection", &Character::setDirection,
		"getDirection", &Character::getDirection,
		"changeMap", &Character::changeMap,
		"stop", &Character::stop,
		"inventory", &Player::inventory,
		"x", &Character::x,
		"y", &Character::y,
		"inFrontOf", &Character::inFrontOf,
		sol::base_classes, sol::bases<Character, Sprite>()
	);

	lua.new_usertype<Sprite>("Sprite",
		sol::constructors<Sprite(const char *, u16, u16)>(),
		"drawFrame", &Sprite::drawFrame,
		"playAnimation", &Sprite::playAnimation,
		"animationAtEnd", &Sprite::animationAtEnd
	);

	lua.new_usertype<LanguageManager>("LanguageManager",
		"getInstance", &LanguageManager::getInstance,
		"translate", &LanguageManager::translate
	);

	doString("function _t(str) return LanguageManager.getInstance():translate(str) end");
}

void LuaHandler::doFile(const char *filename) {
	if(luaL_dofile(lua.lua_state(), filename)) {
		error("%s", lua_tostring(lua.lua_state(), -1));
		lua_pop(lua.lua_state(), 1);
		Game::quit = true;
	}
}

void LuaHandler::doString(const std::string &str) {
	if(luaL_dostring(lua.lua_state(), str.c_str())) {
		error("%s", lua_tostring(lua.lua_state(), -1));
		Game::quit = true;
	}
}

