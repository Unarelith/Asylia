/*
 * =====================================================================================
 *
 *       Filename:  ItemManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2014 19:39:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef ITEMMANAGER_HPP_
#define ITEMMANAGER_HPP_

class ItemManager {
	public:
		static void init();
		
		static void loadItems();
		
		static Item *getItem(u16 id) { return items[id]; }
		
		static std::vector<Item*> items;
};

#endif // ITEMMANAGER_HPP_
