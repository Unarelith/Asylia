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
		
		u16 nbItems() { return m_items.size(); }
		
		Item *getItem(u16 i) { for(auto& it : m_items) if(it.first == ItemManager::items[i]) return it.first; return NULL; }
		
	private:
		std::list<std::pair<Item*, s16>> m_items;
};

#endif // INVENTORY_HPP_
