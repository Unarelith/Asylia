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
		
		void addItem(u8 id, s16 count);
		void removeItem(u8 id, s16 count);
		
		void addArmor(u8 id, s16 count);
		void removeArmor(u8 id, s16 count);
		
		void addWeapon(u8 id, s16 count);
		void removeWeapon(u8 id, s16 count);
		
		void clear();
		
		void add(Inventory *other);
		
		u16 nbItems() { return m_items.size(); }
		u16 nbArmors() { return m_armors.size(); }
		u16 nbWeapons() { return m_weapons.size(); }
		
		Item *getItem(u16 i) { u16 j = 0; for(auto &it : m_items) if(j++ == i) return it.first; return NULL; }
		s16 getItemCount(u16 i) { u16 j = 0; for(auto &it : m_items) if(j++ == i) return it.second; return 0; }
		
		Armor *getArmor(u16 i) { u16 j = 0; for(auto &it : m_armors) if(j++ == i) return it.first; return NULL; }
		s16 getArmorCount(u16 i) { u16 j = 0; for(auto &it : m_armors) if(j++ == i) return it.second; return 0; }
		
		Weapon *getWeapon(u16 i) { u16 j = 0; for(auto &it : m_weapons) if(j++ == i) return it.first; return NULL; }
		s16 getWeaponCount(u16 i) { u16 j = 0; for(auto &it : m_weapons) if(j++ == i) return it.second; return 0; }
		
		void pushBackItem(Item *item, s16 count) { m_items.push_back(std::make_pair(item, count)); }
		
		std::list<std::pair<Item*, s16>> items() { return m_items; }
		std::list<std::pair<Armor*, s16>> armors() { return m_armors; }
		std::list<std::pair<Weapon*, s16>> weapons() { return m_weapons; }
		
		Weapon *weapon() const { return m_weapon; }
		std::list<Armor*> armorlist() { return m_armorlist; }
		Armor *armor(u8 slot) const { for(auto it : m_armorlist) if(it->slot() == slot) return it; return NULL; }
		
		void equipWeapon(Weapon *weapon) { m_weapon = weapon; }
		void equipArmor(Armor *armor);
		
	private:
		std::list<std::pair<Item*, s16>> m_items;
		std::list<std::pair<Armor*, s16>> m_armors;
		std::list<std::pair<Weapon*, s16>> m_weapons;
		
		Weapon *m_weapon;
		std::list<Armor*> m_armorlist;
};

#endif // INVENTORY_HPP_
