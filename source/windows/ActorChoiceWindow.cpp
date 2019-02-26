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

	m_cursorRect = gk::IntRect(0, 0, m_width - 32, (m_height / 4) - 16);
	m_cursorRect.y = (m_cursorRect.height + 11) * m_pos;
}

void ActorChoiceWindow::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	Window::draw(target, states);

	states.transform *= getTransform();

	for(u8 i = 0 ; i < m_itemMax ; i++) {
		u16 y = i * (m_height - 20) / 4;
		u16 charaY = y + ((m_height - 20) / 4 + 15) / 2 - ResourceHelper::getPlayer()->getTeamMember(i)->sprite().frameHeight() / 2;

		gk::Sprite &sprite = ResourceHelper::getPlayer()->getTeamMember(i)->sprite();
		sprite.setPosition(30, charaY);
		target.draw(sprite, states);

			printName(ResourceHelper::getPlayer()->getTeamMember(i), 80, 25 + y, 150, target, states);
			printLevel(ResourceHelper::getPlayer()->getTeamMember(i), 80, 57 + y, 140, target, states);
			printState(ResourceHelper::getPlayer()->getTeamMember(i), 170, 57 + y, 80, target, states);
			printHP(ResourceHelper::getPlayer()->getTeamMember(i), 310, 57 + y, 460, true, target, states);
			printSP(ResourceHelper::getPlayer()->getTeamMember(i), 310, 89 + y, 460, true, target, states);
			printExp(ResourceHelper::getPlayer()->getTeamMember(i), 80, 89 + y, 239, true, target, states);
	}
}

