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
class Item;
class Skill;
class SpriteAnimation;
class Troop;
class Weapon;

class ResourceHelper {
	public:
		static SpriteAnimation &getAnimation(const std::string &name, size_t id);
		static Animation *getAnimationByName(const std::string &name);

		static Item   *getItem(u16 id);
		static Armor  *getArmor(u16 id);
		static Weapon *getWeapon(u16 id);
		static Skill  *getSkill(u16 id);

		static Actor *getActor(u16 id);
		static Enemy *getEnemy(u16 id);
		static Troop *getTroop(u16 id);
};

#endif // RESOURCEHELPER_HPP_
