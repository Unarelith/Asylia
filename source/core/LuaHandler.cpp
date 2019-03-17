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

#include <gk/core/input/GamePad.hpp>
#include <gk/core/ApplicationStateStack.hpp>
#include <gk/core/Exception.hpp>

#include "BattleState.hpp"
#include "Event.hpp"
#include "EventInterpreter.hpp"
#include "GameKey.hpp"
#include "Map.hpp"
#include "MapState.hpp"
#include "MessageState.hpp"
#include "Parameter.hpp"
#include "Player.hpp"
#include "ResourceHelper.hpp"

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
		"x", &Character::x,
		"y", &Character::y,
		"setHitbox", &Character::setHitbox,
		"setPosition", &Character::setPosition,
		"name", &Event::name,
		"face", &Character::face,
		"setVisible", &Event::setVisible,
		sol::base_classes, sol::bases<Character, gk::Sprite>()
	);

	m_lua.new_usertype<EventInterpreter>("EventInterpreter",
		"addActionToQueue", &EventInterpreter::addActionToQueue
	);

	m_lua.new_usertype<gk::Image>("Image",
		sol::constructors<gk::Image(const char*)>()
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

	m_lua.new_usertype<gk::GamePad>("Keyboard",
		"isKeyPressed", &gk::GamePad::isKeyPressed,
		"isKeyPressedWithDelay", &gk::GamePad::isKeyPressedWithDelay,
		"isKeyPressedOnce", &gk::GamePad::isKeyPressedOnce
	);

	doString(
		"Keyboard.GameUp     = " + std::to_string(GameKey::Up) +
		"Keyboard.GameDown   = " + std::to_string(GameKey::Down) +
		"Keyboard.GameLeft   = " + std::to_string(GameKey::Left) +
		"Keyboard.GameRight  = " + std::to_string(GameKey::Right) +
		"Keyboard.GameAttack = " + std::to_string(GameKey::A) +
		"Keyboard.GameBack   = " + std::to_string(GameKey::B) +
		"Keyboard.GameMenu   = " + std::to_string(GameKey::Start)
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
		sol::base_classes, sol::bases<Character, gk::Sprite>()
	);

	m_lua.new_usertype<gk::Sprite>("Sprite",
		sol::constructors<gk::Sprite(const char *, u16, u16)>(),
		"currentAnimation", (gk::SpriteAnimation &(gk::Sprite::*)())&gk::Sprite::currentAnimation,
		"setCurrentAnimation", &gk::Sprite::setCurrentAnimation,
		"setCurrentFrame", &gk::Sprite::setCurrentFrame,
		"setAnimated", &gk::Sprite::setAnimated,
		"updateAnimations", &gk::Sprite::updateAnimations
	);

	m_lua.new_usertype<gk::SpriteAnimation>("SpriteAnimation",
		"isFinished", &gk::SpriteAnimation::isFinished
	);

	m_lua.new_usertype<LanguageManager>("LanguageManager",
		"getInstance", &LanguageManager::getInstance,
		"translate", &LanguageManager::translate
	);

	doString("function _t(str) return LanguageManager.getInstance():translate(str) end");
}

void LuaHandler::doFile(const char *filename) {
	sol::protected_function_result result = m_lua.do_file(filename);
	if (!result.valid()) {
		sol::error err = result;
		throw EXCEPTION("LuaHandler::doFile() failed:", err.what());
	}
}

void LuaHandler::doString(const std::string &str) {
	sol::protected_function_result result = m_lua.do_string(str);
	if (!result.valid()) {
		sol::error err = result;
		throw EXCEPTION("LuaHandler::doString() failed:", err.what());
	}
}

