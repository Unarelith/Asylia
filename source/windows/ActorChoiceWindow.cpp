/*
 * =====================================================================================
 *
 *       Filename:  ActorChoiceWindow.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/06/2014 15:56:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

ActorChoiceWindow::ActorChoiceWindow(s16 x, s16 y, u16 width, u16 height) : SelectableWindow(x, y, width, height) {
	m_itemMax = CharacterManager::player->teamSize();
	
	m_pos = 0;
	
	m_cursor = Rectangle(0, 0, m_width - 32, (m_height / 4) - 16);
}

ActorChoiceWindow::~ActorChoiceWindow() {
}

void ActorChoiceWindow::drawActor(u16 pos) {
	u16 y = pos * (m_height - 20) / 4;
	
	printName(CharacterManager::player->getTeamMember(pos), 80, 25 + y, 150);
	printLevel(CharacterManager::player->getTeamMember(pos), 80, 57 + y, 140);
	printState(CharacterManager::player->getTeamMember(pos), 160, 57 + y, 80);
	printHP(CharacterManager::player->getTeamMember(pos), 310, 57 + y, 460);
	printSP(CharacterManager::player->getTeamMember(pos), 310, 89 + y, 460);
}

void ActorChoiceWindow::draw() {
	Window::draw(false);
	
	for(u8 i = 0 ; i < m_itemMax ; i++) {
		drawActor(i);
	}
}

