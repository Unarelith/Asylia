/*
 * =====================================================================================
 *
 *       Filename:  EquipItemWindow.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/04/2014 16:13:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef EQUIPITEMWINDOW_HPP_
#define EQUIPITEMWINDOW_HPP_

class EquipItemWindow : public SelectableWindow {
	public:
		EquipItemWindow(u8 equipment, u8 equipType);
		~EquipItemWindow();
		
		void drawItem(u8 pos);
		void draw();
		
	private:
		Inventory m_inventory;
};

#endif // ITEMWINDOW_HPP_
