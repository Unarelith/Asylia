/*
 * =====================================================================================
 *
 *       Filename:  CommandWindow.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 13:15:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

CommandWindow::CommandWindow(u16 width, std::vector<std::string> commands) : SelectableWindow(0, 0, width, commands.size() * 32 + 32) {
	m_itemMax = commands.size();
	m_commands = commands;
	
	m_pos = 0;
}

CommandWindow::~CommandWindow() {
}

void CommandWindow::drawItem(u8 pos) {
	Interface::defaultFont->print(m_commands[pos].c_str(), m_x + GameWindow::main->viewportX() + 22, m_y + GameWindow::main->viewportY() + 20 + 32 * pos, FONT_LARGE, Color::white);
}

void CommandWindow::draw() {
	SelectableWindow::draw();
	
	for(u8 i = 0 ; i < m_itemMax ; i++) {
		drawItem(i);
	}
}

