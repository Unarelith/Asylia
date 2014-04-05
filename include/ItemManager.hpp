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

namespace ItemManager {
	void init();
	
	void loadItems();
	
	extern std::vector<Item*> items;
};

#endif // ITEMMANAGER_HPP_
