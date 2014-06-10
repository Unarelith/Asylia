/*
 * =====================================================================================
 *
 *       Filename:  ItemWindow.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  24/03/2014 22:15:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

ItemWindow::ItemWindow(s16 x, s16 y, u16 width, u16 height, Inventory *inventory, s16 infowinX, s16 infowinY) : SelectableWindow(x, y, width, height) {
	m_inventory = new Inventory(*inventory);
	
	m_itemMax = m_inventory->nbItems();
	m_columnMax = 2;
	
	m_pos = 0;
	
	m_infoWindow = new InfoWindow(infowinX, infowinY, width, 52);
}

ItemWindow::~ItemWindow() {
}

void ItemWindow::drawItem(u8 pos) {
	s16 x, y, width;
	
	width = m_width / m_columnMax - 32;
	
	x = 22 + pos % m_columnMax * (width + 32);
	y = 21 + pos / m_columnMax * 32 - m_scroll * 32;
	
	printItem(m_inventory->getItem(pos), m_inventory->getItemCount(pos), x, y, width);
}

void ItemWindow::draw(bool cursor, bool infowinText) {
	SelectableWindow::draw(cursor);
	
	if(infowinText) m_infoWindow->drawTextScaled(m_inventory->getItem(m_pos)->description());
	else m_infoWindow->drawTextScaled(" ");
	
	for(u8 i = 0 ; i < m_itemMax ; i++) {
		drawItem(i);
	}
}

void ItemWindow::changeSet(u8 equipID, u8 equipType, Equipment *equipment) {
	m_inventory->clear();
	
	if(equipID == 0) {
		for(auto& it : CharacterManager::player->inventory()->weapons()) {
			if(!std::get<0>(it)->equipped() && std::get<0>(it)->equipType() == equipType && std::get<0>(it) != equipment->weapon()) {
				m_inventory->pushBackItem((Item*)std::get<0>(it), std::get<1>(it));
			}
		}
	} else {
		for(auto& it : CharacterManager::player->inventory()->armors()) {
			if(!std::get<0>(it)->equipped() && std::get<0>(it)->slot() == equipType && std::get<0>(it) != equipment->armor(std::get<0>(it)->slot())) {
				m_inventory->pushBackItem((Item*)std::get<0>(it), std::get<1>(it));
			}
		}
	}
	
	m_itemMax = m_inventory->nbItems();
}

Item *ItemWindow::currentItem() {
	return m_inventory->getItem(m_pos);
}

