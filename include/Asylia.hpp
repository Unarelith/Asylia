/*
 * =====================================================================================
 *
 *       Filename:  Asylia.hpp
 *
 *    Description:
 *
 *        Created:  14/03/2014 21:41:50
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
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
#include <algorithm>

#ifdef __ANDROID__
	std::string to_string(int n);
#else
	#define to_string(n) std::to_string(n)
#endif

#include "LuaHandler.hpp"

#include <tinyxml2.h>

using namespace tinyxml2;

#include "SDLHeaders.hpp"
#include "SDLManager.hpp"

#include "Types.hpp"
#include "Config.hpp"
#include "Debug.hpp"

#include "XMLFile.hpp"

#include "Color.hpp"
#include "Rectangle.hpp"

#include "Parameter.hpp"

#include "LanguageManager.hpp"

#include "Sound.hpp"

#include "Keyboard.hpp"

#include "Game.hpp"
#include "GameWindow.hpp"

#include "TimeManager.hpp"

#include "Image.hpp"

#include "Font.hpp"

#include "Timer.hpp"
#include "SpriteAnimation.hpp"
#include "SpriteAnimationManager.hpp"
#include "Sprite.hpp"
#include "Animation.hpp"
#include "AnimationManager.hpp"

#include "Item.hpp"
#include "Armor.hpp"
#include "Weapon.hpp"
#include "Skill.hpp"
#include "ItemManager.hpp"

#include "Inventory.hpp"
#include "Equipment.hpp"

#include "QuestObjective.hpp"
#include "Quest.hpp"
#include "QuestManager.hpp"

#include "Battler.hpp"
#include "Enemy.hpp"
#include "Actor.hpp"
#include "BattlerManager.hpp"

#include "Troop.hpp"
#include "TroopManager.hpp"

#include "BattleAction.hpp"
#include "Battle.hpp"

#include "Window.hpp"
#include "TextWindow.hpp"
#include "InfoWindow.hpp"
#include "SelectableWindow.hpp"
#include "CommandWindow.hpp"
#include "ItemWindow.hpp"
#include "EquipStatsWindow.hpp"
#include "EquipChoiceWindow.hpp"
#include "ActorStatsWindow.hpp"
#include "BattleChoiceWindow.hpp"
#include "BattleActionWindow.hpp"
#include "VictoryWindow.hpp"
#include "ActorChoiceWindow.hpp"
#include "QuestInfoWindow.hpp"

#include "Character.hpp"
#include "Player.hpp"
#include "CharacterManager.hpp"

#include "Interface.hpp"

#include "EventAction.hpp"
#include "Event.hpp"
#include "EventManager.hpp"
#include "EventListener.hpp"

#include "ApplicationState.hpp"
#include "MapState.hpp"
#include "MessageState.hpp"
#include "MenuState.hpp"
#include "LuaState.hpp"
#include "TitleState.hpp"
#include "EndState.hpp"
#include "ItemState.hpp"
#include "EquipState.hpp"
#include "BattleState.hpp"
#include "SettingsState.hpp"
#include "QuestState.hpp"
#include "StateManager.hpp"

#include "EventInterpreter.hpp"

#include "Tileset.hpp"
#include "Map.hpp"
#include "MapManager.hpp"

#include "SaveManager.hpp"

#endif // ASYLIA_HPP_
