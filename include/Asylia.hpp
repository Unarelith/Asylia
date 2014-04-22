/*
 * =====================================================================================
 *
 *       Filename:  Asylia.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/03/2014 21:41:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef ASYLIA_HPP_
#define ASYLIA_HPP_

#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <utility>

#ifdef __ANDROID__
	std::string to_string(int n);
#else
	#define to_string(n) std::to_string(n)
#endif

#include "AndroidIO.hpp"

#include "lua.hpp"
#include "SLB.hpp"
#include "LuaHandler.hpp"

#include "tinyxml2.hpp"

using namespace tinyxml2;

#include "SDLHeaders.hpp"
#include "SDLManager.hpp"

#include "Types.hpp"
#include "Config.hpp"
#include "Debug.hpp"

#include "Color.hpp"
#include "Rectangle.hpp"

#include "LanguageManager.hpp"

#include "Sound.hpp"

#include "Keyboard.hpp"

#include "Game.hpp"
#include "GameWindow.hpp"

#include "TimeManager.hpp"

#include "Image.hpp"

#include "Font.hpp"

#include "Timer.hpp"
#include "Animation.hpp"
#include "AnimationManager.hpp"
#include "Sprite.hpp"

#include "Item.hpp"
#include "Armor.hpp"
#include "Weapon.hpp"
#include "ItemManager.hpp"

#include "Inventory.hpp"

#include "Battler.hpp"
#include "Enemy.hpp"
#include "Actor.hpp"

#include "Window.hpp"
#include "TextWindow.hpp"
#include "InfoWindow.hpp"
#include "SelectableWindow.hpp"
#include "CommandWindow.hpp"
#include "MessageWindow.hpp"
#include "ItemWindow.hpp"
#include "EquipItemWindow.hpp"
#include "EquipStatsWindow.hpp"
#include "EquipChoiceWindow.hpp"
#include "ActorStatsWindow.hpp"

#include "Character.hpp"
#include "Player.hpp"
#include "CharacterManager.hpp"

#include "Interface.hpp"

#include "Event.hpp"

#include "Activity.hpp"
#include "MapActivity.hpp"
#include "DialogActivity.hpp"
#include "MenuActivity.hpp"
#include "LuaActivity.hpp"
#include "TitleActivity.hpp"
#include "EndActivity.hpp"
#include "ItemActivity.hpp"
#include "EquipActivity.hpp"
#include "BattleActivity.hpp"
#include "ActivityManager.hpp"

#include "Tileset.hpp"
#include "Map.hpp"
#include "MapManager.hpp"

#endif // ASYLIA_HPP_
