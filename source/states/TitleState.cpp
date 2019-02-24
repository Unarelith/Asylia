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
#include <gk/core/input/GamePad.hpp>
#include <gk/core/ApplicationStateStack.hpp>

#include "Config.hpp"
#include "GameKey.hpp"
#include "MapState.hpp"
#include "TitleState.hpp"

TitleState::TitleState() {
	m_cmdwin.addCommand("NewGame");
	m_cmdwin.addCommand("Continue", true);
	m_cmdwin.addCommand("Quit");

	m_cmdwin.x(SCREEN_WIDTH / 2 - m_cmdwin.width() / 2);
	m_cmdwin.y(SCREEN_HEIGHT / 2 + int(SCREEN_HEIGHT / 10));

	gk::AudioPlayer::playMusic("music-title");
}

void TitleState::update() {
	m_cmdwin.update();

	if(gk::GamePad::isKeyPressedOnce(GameKey::A)) {
		if(m_cmdwin.disabled(m_cmdwin.pos())) {
			gk::AudioPlayer::playSound("sound-blocked");
			return;
		}

		gk::AudioPlayer::playSound("sound-confirm");

		switch(m_cmdwin.pos()) {
			case 0:
				gk::ApplicationStateStack::getInstance().clear();
				gk::ApplicationStateStack::getInstance().push<MapState>();
				break;
			case 1: break;
			case 2:
				SDL_Delay(100);
				gk::ApplicationStateStack::getInstance().clear();
				break;
			default: break;
		}
	}
}

void TitleState::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	target.draw(m_background, states);
	// m_cmdwin.draw(); // FIXME
}

