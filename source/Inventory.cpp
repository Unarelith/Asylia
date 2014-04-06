/*
 * =====================================================================================
 *
 *       Filename:  Inventory.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2014 18:12:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Inventory::Inventory() {
}

Inventory::~Inventory() {
}

void Inventory::addItem(u8 id, u8 count) {
	for(auto& it : m_items) {
		if(it.first == ItemManager::items[id]) {
			it.second += count;
			if(it.second > 99) it.second = 99;
			return;
		}
	}
	
	m_items.push_back(std::make_pair(ItemManager::items[id], count));
}

void Inventory::removeItem(u8 id, u8 count) {
	for(auto& it : m_items) {
		if(it.first == ItemManager::items[id]) {
			it.second -= count;
		}
	}
	
	m_items.remove_if([](std::pair<Item*, s16>& element) {
		return element.second < 1;
	});
}

