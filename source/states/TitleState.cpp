/*
 * =====================================================================================
 *
 *       Filename:  TitleState.cpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 17:20:07
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/audio/AudioPlayer.hpp>

#include "ApplicationStateStack.hpp"
#include "GameWindow.hpp"
#include "Keyboard.hpp"
#include "MapState.hpp"
#include "TitleState.hpp"

TitleState::TitleState() {
	m_type = Type::TitleScreen;

	m_cmdwin.addCommand("NewGame");
	m_cmdwin.addCommand("Continue", true);
	m_cmdwin.addCommand("Quit");

	m_cmdwin.x(GameWindow::main->width() / 2 - m_cmdwin.width() / 2);
	m_cmdwin.y(GameWindow::main->height() / 2 + int(GameWindow::main->height() / 10));

	gk::AudioPlayer::playMusic("music-title");
}

void TitleState::update() {
	m_cmdwin.update();

	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		if(m_cmdwin.disabled(m_cmdwin.pos())) {
			gk::AudioPlayer::playSound("sound-blocked");
			return;
		}

		gk::AudioPlayer::playSound("sound-confirm");

		switch(m_cmdwin.pos()) {
			case 0:
				ApplicationStateStack::getInstance().push<MapState>();
				break;
			case 1: break;
			case 2:
				SDL_Delay(100);
				ApplicationStateStack::getInstance().clear();
				break;
			default: break;
		}
	}
}

void TitleState::render() {
	m_background.renderCopy();
	m_cmdwin.draw();
}

