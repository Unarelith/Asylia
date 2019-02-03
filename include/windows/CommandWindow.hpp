/*
 * =====================================================================================
 *
 *       Filename:  CommandWindow.hpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 13:13:37
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef COMMANDWINDOW_HPP_
#define COMMANDWINDOW_HPP_

#include "SelectableWindow.hpp"

class CommandWindow : public SelectableWindow {
	public:
		CommandWindow(s16 x, s16 y, u16 width, bool horizontal = false, bool centered = false);
		CommandWindow(u16 width);
		~CommandWindow();

		void clear() { m_commands.clear(); if(m_horizontal) m_height = 64; else m_height = 32; m_itemMax = 0; }

		void addCommand(std::string cmd, bool disabled = false) { if(!m_horizontal) m_height += 32; m_commands.push_back(std::make_pair(cmd, disabled)); m_itemMax++; }

		void drawItem(u8 pos);
		void drawHorizontalCenteredItem(u8 pos);
		void draw(bool cursor = true);

		bool disabled(u8 pos) { return m_commands[pos].second; }

		std::vector<std::pair<std::string,bool>> commands() { return m_commands; }

	private:
		std::vector<std::pair<std::string,bool>> m_commands;

		bool m_horizontal;
		bool m_centered;
};

#endif // COMMANDWINDOW_HPP_
