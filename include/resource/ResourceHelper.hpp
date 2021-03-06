/*
 * =====================================================================================
 *
 *       Filename:  ResourceHelper.hpp
 *
 *    Description:
 *
 *        Created:  17/02/2019 21:22:55
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef RESOURCEHELPER_HPP_
#define RESOURCEHELPER_HPP_

#include <string>

#include <gk/core/IntTypes.hpp>

class Actor;
class Animation;
class Armor;
class Enemy;
class Event;
class Font;
class Image;
class Item;
class Map;
class Quest;
class Player;
class Skill;
class SpriteAnimation;
class Tileset;
class Troop;
class Weapon;

class ResourceHelper {
	public:
		static Image &getImage(const std::string &name);
		static Font &getFont(const std::string &name);

		static SpriteAnimation &getAnimation(const std::string &name, size_t id);
		static Animation *getAnimationByName(const std::string &name);

		static Item   *getItem(u16 id);
		static Armor  *getArmor(u16 id);
		static Weapon *getWeapon(u16 id);
		static Skill  *getSkill(u16 id);

		static Actor *getActor(u16 id);
		static Enemy *getEnemy(u16 id);
		static Troop *getTroop(u16 id);

		static Quest *getQuest(u16 id);

		static Player *getPlayer();
		static Event *getEvent(const std::string &name);

		static Tileset *getTileset(u16 id);

		static Map *getMap(u16 area, u16 x, u16 y);
		static Map *getCurrentMap() { return s_currentMap; }
		static void setCurrentMap(Map *currentMap) { s_currentMap = currentMap; }

	private:
		static Map *s_currentMap;
};

#endif // RESOURCEHELPER_HPP_
