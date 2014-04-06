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
		
		void addItem(u8 id, u8 count);
		void removeItem(u8 id, u8 count);
		
		void addArmor(u8 id, u8 count);
		void removeArmor(u8 id, u8 count);
		
		void addWeapon(u8 id, u8 count);
		void removeWeapon(u8 id, u8 count);
		
		u16 nbItems() { return m_items.size(); }
		u16 nbArmors() { return m_armors.size(); }
		u16 nbWeapons() { return m_weapons.size(); }
		
		Item *getItem(u16 i) { for(auto& it : m_items) if(it.first == ItemManager::items[i]) return it.first; return NULL; }
		s16 getItemCount(u16 i) { for(auto& it : m_items) if(it.first == ItemManager::items[i]) return it.second; return 0; }
		
		Armor *getArmor(u16 i) { for(auto& it : m_armors) if(it.first == ItemManager::armors[i]) return it.first; return NULL; }
		s16 getArmorCount(u16 i) { for(auto& it : m_armors) if(it.first == ItemManager::armors[i]) return it.second; return 0; }
		
		Weapon *getWeapon(u16 i) { for(auto& it : m_weapons) if(it.first == ItemManager::weapons[i]) return it.first; return NULL; }
		s16 getWeaponCount(u16 i) { for(auto& it : m_weapons) if(it.first == ItemManager::weapons[i]) return it.second; return 0; }
		
	private:
		std::list<std::pair<Item*, s16>> m_items;
		std::list<std::pair<Armor*, s16>> m_armors;
		std::list<std::pair<Weapon*, s16>> m_weapons;
};

#endif // INVENTORY_HPP_
