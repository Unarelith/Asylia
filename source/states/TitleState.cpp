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
#include "Game.hpp"
#include "GameWindow.hpp"
#include "Keyboard.hpp"
#include "MapState.hpp"
#include "Sound.hpp"
#include "ApplicationStateStack.hpp"
#include "TitleState.hpp"

TitleState::TitleState() {
	m_type = Type::TitleScreen;

	m_cmdwin.addCommand("NewGame");
	m_cmdwin.addCommand("Continue", true);
	m_cmdwin.addCommand("Quit");

	m_cmdwin.x(GameWindow::main->width() / 2 - m_cmdwin.width() / 2);
	m_cmdwin.y(GameWindow::main->height() / 2 + int(GameWindow::main->height() / 10));

	Sound::Music::play(Sound::Music::title, -1);
}

void TitleState::update() {
	m_cmdwin.update();

	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		if(m_cmdwin.disabled(m_cmdwin.pos())) {
			Sound::Effect::play(Sound::Effect::blocked);
			return;
		}

		Sound::Effect::play(Sound::Effect::confirm);

		switch(m_cmdwin.pos()) {
			case 0:
				ApplicationStateStack::getInstance().push<MapState>().init();
				break;
			case 1: break;
			case 2:
				SDL_Delay(100);
				Game::quit = true;
				break;
			default: break;
		}
	}
}

void TitleState::render() {
	m_background.renderCopy();
	m_cmdwin.draw();
}

