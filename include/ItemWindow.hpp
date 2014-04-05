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
		ItemWindow();
		~ItemWindow();
		
		void addItem(std::string item);
		
		void drawItem(u8 pos);
		void draw();
		
	private:
		std::vector<std::string> m_items;
};

#endif // ITEMWINDOW_HPP_