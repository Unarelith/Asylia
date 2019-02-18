/*
 * =====================================================================================
 *
 *       Filename:  ActorChoiceWindow.cpp
 *
 *    Description:
 *
 *        Created:  10/06/2014 15:56:06
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "ActorChoiceWindow.hpp"
#include "Player.hpp"
#include "ResourceHelper.hpp"

ActorChoiceWindow::ActorChoiceWindow(s16 x, s16 y, u16 width, u16 height) : SelectableWindow(x, y, width, height) {
	m_itemMax = ResourceHelper::getPlayer()->teamSize();

	m_pos = 0;
}

void ActorChoiceWindow::update() {
	SelectableWindow::update();

	m_cursor = gk::IntRect(0, 0, m_width - 32, (m_height / 4) - 16);
	m_cursor.y = (m_cursor.height + 11) * m_pos;
}

void ActorChoiceWindow::drawActor(u16 pos) {
	u16 y = pos * (m_height - 20) / 4;
	u16 charaY = m_y + y + ((m_height - 20) / 4 + 15) / 2 - ResourceHelper::getPlayer()->getTeamMember(pos)->sprite()->frameHeight() / 2;

	ResourceHelper::getPlayer()->getTeamMember(pos)->sprite()->playAnimation(m_x + 30, charaY, 0);

	printName(ResourceHelper::getPlayer()->getTeamMember(pos), 80, 25 + y, 150);
	printLevel(ResourceHelper::getPlayer()->getTeamMember(pos), 80, 57 + y, 140);
	printState(ResourceHelper::getPlayer()->getTeamMember(pos), 170, 57 + y, 80);
	printHP(ResourceHelper::getPlayer()->getTeamMember(pos), 310, 57 + y, 460, true);
	printSP(ResourceHelper::getPlayer()->getTeamMember(pos), 310, 89 + y, 460, true);
	printExp(ResourceHelper::getPlayer()->getTeamMember(pos), 80, 89 + y, 239, true);
}

void ActorChoiceWindow::draw() {
	Window::draw();

	for(u8 i = 0 ; i < m_itemMax ; i++) {
		drawActor(i);
	}
}

