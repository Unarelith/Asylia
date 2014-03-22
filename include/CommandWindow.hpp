/*
 * =====================================================================================
 *
 *       Filename:  CommandWindow.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 13:13:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef COMMANDWINDOW_HPP_
#define COMMANDWINDOW_HPP_

class CommandWindow : public SelectableWindow {
	public:
		CommandWindow(s16 x, s16 y, u16 width, std::vector<std::string> commands);
		~CommandWindow();
		
		void drawItem(u8 pos);
		void draw();
		
	private:
		std::vector<std::string> m_commands;
};

#endif // COMMANDWINDOW_HPP_
