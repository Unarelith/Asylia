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

void Inventory::addArmor(u8 id, u8 count) {
	for(auto& it : m_armors) {
		if(it.first == ItemManager::armors[id]) {
			it.second += count;
			if(it.second > 99) it.second = 99;
			return;
		}
	}
	
	m_armors.push_back(std::make_pair(ItemManager::armors[id], count));
}

void Inventory::removeArmor(u8 id, u8 count) {
	for(auto& it : m_armors) {
		if(it.first == ItemManager::armors[id]) {
			it.second -= count;
		}
	}
	
	m_armors.remove_if([](std::pair<Armor*, s16>& element) {
		return element.second < 1;
	});
}

void Inventory::addWeapon(u8 id, u8 count) {
	for(auto& it : m_weapons) {
		if(it.first == ItemManager::weapons[id]) {
			it.second += count;
			if(it.second > 99) it.second = 99;
			return;
		}
	}
	
	m_weapons.push_back(std::make_pair(ItemManager::weapons[id], count));
}

void Inventory::removeWeapon(u8 id, u8 count) {
	for(auto& it : m_weapons) {
		if(it.first == ItemManager::weapons[id]) {
			it.second -= count;
		}
	}
	
	m_weapons.remove_if([](std::pair<Weapon*, s16>& element) {
		return element.second < 1;
	});
}

