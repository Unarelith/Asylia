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
		CommandWindow(s16 x, s16 y, u16 width, u16 height, bool horizontal = false, bool centered = false);
		CommandWindow(u16 width, std::vector<std::string> commands);
		~CommandWindow();
		
		void addCommand(std::string cmd) { m_commands.push_back(cmd); m_itemMax++; };
		
		void drawItem(u8 pos);
		void drawHorizontalCenteredItem(u8 pos);
		void draw(bool cursor = true);
		
	private:
		std::vector<std::string> m_commands;
		
		bool m_horizontal;
		bool m_centered;
};

#endif // COMMANDWINDOW_HPP_
