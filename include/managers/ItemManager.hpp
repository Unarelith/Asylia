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

#include <memory>

#include "Armor.hpp"
#include "Weapon.hpp"
#include "Skill.hpp"

class ItemManager : public Singleton<ItemManager> {
	public:
		void init();

		void loadItems();
		void loadArmors();
		void loadWeapons();
		void loadSkills();

		Item *getItem(u16 id) { return m_items[id].get(); }
		Armor *getArmor(u16 id) { return m_armors[id].get(); }
		Weapon *getWeapon(u16 id) { return m_weapons[id].get(); }
		Skill *getSkill(u16 id) { return m_skills[id].get(); }

		std::vector<std::unique_ptr<Armor>> &armors() { return m_armors; }

	private:
		std::vector<std::unique_ptr<Item>> m_items;
		std::vector<std::unique_ptr<Armor>> m_armors;
		std::vector<std::unique_ptr<Weapon>> m_weapons;
		std::vector<std::unique_ptr<Skill>> m_skills;
};

#endif // ITEMMANAGER_HPP_
