/*
 * =====================================================================================
 *
 *       Filename:  ItemWindow.hpp
 *
 *    Description:
 *
 *        Created:  24/03/2014 22:13:29
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ITEMWINDOW_HPP_
#define ITEMWINDOW_HPP_

#include "Equipment.hpp"
#include "Inventory.hpp"
#include "SelectableWindow.hpp"

class ItemWindow : public SelectableWindow {
	public:
		ItemWindow(s16 x, s16 y, u16 width, u16 height, Inventory *inventory, s16 infowinX = 0, s16 infowinY = 0);

		void update(bool infowinText = true);

		// void drawItem(u8 pos);
		// void draw(bool cursor = true, bool infoWinText = true);

		void changeSet(u8 equipID, u8 equipType, Equipment *equipment);

		bool hasItems() { return m_inventory->items().size(); }

		Item *currentItem();

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		Inventory *m_inventory;

		mutable gk::Text m_text{"font-default", 18}; // FIXME
};

#endif // ITEMWINDOW_HPP_
