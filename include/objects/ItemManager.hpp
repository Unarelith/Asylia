/*
 * =====================================================================================
 *
 *       Filename:  ItemManager.hpp
 *
 *    Description:
 *
 *        Created:  05/04/2014 19:39:04
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ITEMMANAGER_HPP_
#define ITEMMANAGER_HPP_

#include "Armor.hpp"
#include "Weapon.hpp"
#include "Skill.hpp"

class ItemManager {
	public:
		static void init();
		static void free();

		static void loadItems();
		static void loadArmors();
		static void loadWeapons();
		static void loadSkills();

		static Item *getItem(u16 id) { return items[id]; }
		static Armor *getArmor(u16 id) { return armors[id]; }
		static Weapon *getWeapon(u16 id) { return weapons[id]; }
		static Skill *getSkill(u16 id) { return skills[id]; }

		static std::vector<Item*> items;
		static std::vector<Armor*> armors;
		static std::vector<Weapon*> weapons;
		static std::vector<Skill*> skills;
};

#endif // ITEMMANAGER_HPP_
