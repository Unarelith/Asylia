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

#include <gk/core/ApplicationStateStack.hpp>

#include "BattleState.hpp"
#include "Event.hpp"
#include "EventInterpreter.hpp"
#include "Keyboard.hpp"
#include "Map.hpp"
#include "MapState.hpp"
#include "MessageState.hpp"
#include "Parameter.hpp"
#include "Player.hpp"
#include "ResourceHelper.hpp"
#include "Sprite.hpp"

template<>
LuaHandler *Singleton<LuaHandler>::s_instance = nullptr;

void LuaHandler::init() {
	m_lua.open_libraries(
		sol::lib::base,
		sol::lib::math,
		sol::lib::table
	);

	bindClasses();
}

void LuaHandler::bindClasses() {
	m_lua["drawMessage"] = [&](const std::string &message) {
		return &gk::ApplicationStateStack::getInstance().push<MessageState>(message);
	};

	m_lua.new_usertype<Event>("Event",
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

	m_lua.new_usertype<EventInterpreter>("EventInterpreter",
		"addActionToQueue", &EventInterpreter::addActionToQueue
	);

	m_lua.new_usertype<Image>("Image",
		sol::constructors<Image(const char*)>(),
		"renderCopy", &Image::renderCopy,
		"render", &Image::render
	);

	m_lua.new_usertype<Inventory>("Inventory",
		"addItem", &Inventory::addItem
	);

	m_lua.new_usertype<Item>("Item",
		"name", &Item::name
	);

	m_lua.new_usertype<ResourceHelper>("ResourceHelper",
		"getItem", &ResourceHelper::getItem,
		"getCurrentMap", &ResourceHelper::getCurrentMap,
		"getPlayer", &ResourceHelper::getPlayer
	);

	m_lua.new_usertype<Keyboard>("Keyboard",
		"isKeyPressed", &Keyboard::isKeyPressed,
		"isKeyPressedWithDelay", &Keyboard::isKeyPressedWithDelay,
		"isKeyPressedOnce", &Keyboard::isKeyPressedOnce
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

	m_lua.new_usertype<Map>("Map",
		"getEvent", &Map::getEvent,
		"scrollX", &Map::getScrollX,
		"scrollY", &Map::getScrollY
	);

	m_lua.new_usertype<BattleState>("BattleState");

	m_lua.new_usertype<MapState>("MapState");

	m_lua.new_usertype<MessageState>("MessageState",
		"addCommand", &MessageState::addCommand,
		"getCmdwinPos", &MessageState::getCmdwinPos
	);

	m_lua.new_usertype<ParameterList>("ParameterList",
		"addIntParameter", &ParameterList::addIntParameter,
		"addBoolParameter", &ParameterList::addBoolParameter,
		"addFloatParameter", &ParameterList::addFloatParameter,
		"addStringParameter", &ParameterList::addStringParameter,
		"clear", &ParameterList::clear
	);

	m_lua.new_usertype<IntParameter>("IntParameter");
	m_lua.new_usertype<FloatParameter>("FloatParameter");
	m_lua.new_usertype<StringParameter>("StringParameter");

	m_lua.new_usertype<Player>("Player",
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

	m_lua.new_usertype<Sprite>("Sprite",
		sol::constructors<Sprite(const char *, u16, u16)>(),
		"drawFrame", &Sprite::drawFrame,
		"playAnimation", &Sprite::playAnimation,
		"animationAtEnd", &Sprite::animationAtEnd
	);

	m_lua.new_usertype<LanguageManager>("LanguageManager",
		"getInstance", &LanguageManager::getInstance,
		"translate", &LanguageManager::translate
	);

	doString("function _t(str) return LanguageManager.getInstance():translate(str) end");
}

void LuaHandler::doFile(const char *filename) {
	m_lua.do_file(filename);
}

void LuaHandler::doString(const std::string &str) {
	m_lua.do_string(str);
}

