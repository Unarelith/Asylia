/*
 * =====================================================================================
 *
 *       Filename:  EndState.cpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 17:47:35
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/audio/AudioPlayer.hpp>
#include <gk/core/input/GamePad.hpp>
#include <gk/core/ApplicationStateStack.hpp>

#include "EndState.hpp"
#include "GameKey.hpp"
#include "GameWindow.hpp"
#include "TitleState.hpp"

EndState::EndState(bool disableCancel) {
	if(!disableCancel) m_cmdwin.addCommand("Cancel");
	m_cmdwin.addCommand("TitleScreen");
	m_cmdwin.addCommand("Quit");

	m_cmdwin.x(GameWindow::main->width() / 2 - m_cmdwin.width() / 2);
	m_cmdwin.y(GameWindow::main->height() / 2 - m_cmdwin.height() / 2);
}

void EndState::update() {
	m_cmdwin.update();

	if(gk::GamePad::isKeyPressedOnce(GameKey::A)) {
		if(m_cmdwin.disabled(m_cmdwin.pos())) {
			gk::AudioPlayer::playSound("sound-blocked");
			return;
		}

		gk::AudioPlayer::playSound("sound-confirm");

		u8 n = m_cmdwin.pos();
		if(m_cmdwin.commands().size() == 2) {
			n++;
		}

		switch(n) {
			case 0:
				gk::ApplicationStateStack::getInstance().pop();
				break;
			case 1:
				gk::ApplicationStateStack::getInstance().clear();
				gk::ApplicationStateStack::getInstance().push<TitleState>();
				break;
			case 2:
				SDL_Delay(100);
				gk::ApplicationStateStack::getInstance().clear();
				break;
			default: break;
		}
	}

	if(gk::GamePad::isKeyPressedOnce(GameKey::B)) {
		gk::AudioPlayer::playSound("sound-back");
		gk::ApplicationStateStack::getInstance().pop();
	}
}

void EndState::render() {
	m_cmdwin.draw();
}

