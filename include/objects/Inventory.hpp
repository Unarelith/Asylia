/*
 * =====================================================================================
 *
 *       Filename:  Inventory.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2014 18:08:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef INVENTORY_HPP_
#define INVENTORY_HPP_

class Inventory {
	public:
		Inventory();
		~Inventory();
		
		void addItem(u8 id, s16 count, double chance = 1);
		void removeItem(u8 id, s16 count);
		
		void addArmor(u8 id, s16 count, double chance = 1);
		void removeArmor(u8 id, s16 count);
		
		void addWeapon(u8 id, s16 count, double chance = 1);
		void removeWeapon(u8 id, s16 count);
		
		void add(Inventory *other, bool withChance = false);
		
		u16 nbItems() { return m_items.size(); }
		u16 nbArmors() { return m_armors.size(); }
		u16 nbWeapons() { return m_weapons.size(); }
		
		Item *getItem(u16 i) { u16 j = 0; for(auto &it : m_items) if(j++ == i) return std::get<0>(it); return NULL; }
		s16 getItemCount(u16 i) { u16 j = 0; for(auto &it : m_items) if(j++ == i) return std::get<1>(it); return 0; }
		
		Armor *getArmor(u16 i) { u16 j = 0; for(auto &it : m_armors) if(j++ == i) return std::get<0>(it); return NULL; }
		s16 getArmorCount(u16 i) { u16 j = 0; for(auto &it : m_armors) if(j++ == i) return std::get<1>(it); return 0; }
		
		Weapon *getWeapon(u16 i) { u16 j = 0; for(auto &it : m_weapons) if(j++ == i) return std::get<0>(it); return NULL; }
		s16 getWeaponCount(u16 i) { u16 j = 0; for(auto &it : m_weapons) if(j++ == i) return std::get<1>(it); return 0; }
		
		void pushBackItem(Item *item, s16 count, double chance = 1) { m_items.push_back(std::make_tuple(item, count, chance)); }
		
		std::list<std::tuple<Item*, s16, double>> items() { return m_items; }
		std::list<std::tuple<Armor*, s16, double>> armors() { return m_armors; }
		std::list<std::tuple<Weapon*, s16, double>> weapons() { return m_weapons; }
		
	private:
		std::list<std::tuple<Item*, s16, double>> m_items;
		std::list<std::tuple<Armor*, s16, double>> m_armors;
		std::list<std::tuple<Weapon*, s16, double>> m_weapons;
};

#endif // INVENTORY_HPP_
