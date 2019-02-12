/*
 * =====================================================================================
 *
 *       Filename:  Inventory.cpp
 *
 *    Description:
 *
 *        Created:  05/04/2014 18:12:14
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Inventory.hpp"
#include "ItemManager.hpp"

Inventory::Inventory() {
}

Inventory::~Inventory() {
	clear();
}

void Inventory::clear() {
	m_items.clear();
	m_armors.clear();
	m_weapons.clear();
}

void Inventory::addItem(u8 id, s16 count, double chance) {
	for(auto &it : m_items) {
		if(std::get<0>(it) == ItemManager::getInstance().getItem(id)) {
			std::get<1>(it) += count;
			if(std::get<1>(it) > 99) std::get<1>(it) = 99;
			return;
		}
	}

	m_items.push_back(std::make_tuple(ItemManager::getInstance().getItem(id), count, chance));
}

void Inventory::removeItem(u8 id, s16 count) {
	for(auto &it : m_items) {
		if(std::get<0>(it) == ItemManager::getInstance().getItem(id)) {
			std::get<1>(it) -= count;
		}
	}

	m_items.remove_if([](std::tuple<Item*, s16, double>& element) {
		return std::get<1>(element) < 1;
	});
}

void Inventory::addArmor(u8 id, s16 count, double chance) {
	for(auto &it : m_armors) {
		if(std::get<0>(it) == ItemManager::getInstance().getArmor(id)) {
			std::get<1>(it) += count;
			if(std::get<1>(it) > 99) std::get<1>(it) = 99;
			return;
		}
	}

	m_armors.push_back(std::make_tuple(ItemManager::getInstance().getArmor(id), count, chance));
}

void Inventory::removeArmor(u8 id, s16 count) {
	for(auto &it : m_armors) {
		if(std::get<0>(it) == ItemManager::getInstance().getArmor(id)) {
			std::get<1>(it) -= count;
		}
	}

	m_armors.remove_if([](std::tuple<Armor*, s16, double>& element) {
		return std::get<1>(element) < 1;
	});
}

void Inventory::addWeapon(u8 id, s16 count, double chance) {
	for(auto &it : m_weapons) {
		if(std::get<0>(it) == ItemManager::getInstance().getWeapon(id)) {
			std::get<1>(it) += count;
			if(std::get<1>(it) > 99) std::get<1>(it) = 99;
			return;
		}
	}

	m_weapons.push_back(std::make_tuple(ItemManager::getInstance().getWeapon(id), count, chance));
}

void Inventory::removeWeapon(u8 id, s16 count) {
	for(auto &it : m_weapons) {
		if(std::get<0>(it) == ItemManager::getInstance().getWeapon(id)) {
			std::get<1>(it) -= count;
		}
	}

	m_weapons.remove_if([](std::tuple<Weapon*, s16, double>& element) {
		return std::get<1>(element) < 1;
	});
}

void Inventory::add(Inventory *other, bool withChance) {
	for(auto &it : other->m_items) {
		if(!withChance || rand()%101 <= std::get<2>(it) * 100) addItem(std::get<0>(it)->id(), std::get<1>(it));
	}
	for(auto &it : other->m_armors) {
		if(!withChance || rand()%101 <= std::get<2>(it) * 100) addItem(std::get<0>(it)->id(), std::get<1>(it));
	}
	for(auto &it : other->m_weapons) {
		if(!withChance || rand()%101 <= std::get<2>(it) * 100) addItem(std::get<0>(it)->id(), std::get<1>(it));
	}
}

