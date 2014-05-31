/*
 * =====================================================================================
 *
 *       Filename:  ItemWindow.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  24/03/2014 22:13:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef ITEMWINDOW_HPP_
#define ITEMWINDOW_HPP_

class ItemWindow : public SelectableWindow {
	public:
		ItemWindow(s16 x, s16 y, u16 width, u16 height, s16 infowinX = 0, s16 infowinY = 0);
		~ItemWindow();
		
		void drawItem(u8 pos);
		void draw(bool cursor = true, bool infoWinText = true);
		
		void changeSet(u8 equipment, u8 equipType);
		
		bool hasItems() { return m_inventory.items().size(); }
		
		Item *currentItem();
		
	private:
		Inventory m_inventory;
};

#endif // ITEMWINDOW_HPP_
