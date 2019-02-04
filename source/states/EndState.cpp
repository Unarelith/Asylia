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
#include "EndState.hpp"
#include "Game.hpp"
#include "GameWindow.hpp"
#include "Keyboard.hpp"
#include "ApplicationStateStack.hpp"
#include "Sound.hpp"
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

	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		if(m_cmdwin.disabled(m_cmdwin.pos())) {
			Sound::Effect::play(Sound::Effect::blocked);
			return;
		}

		Sound::Effect::play(Sound::Effect::confirm);

		u8 n = m_cmdwin.pos();
		if(m_cmdwin.commands().size() == 2) {
			n++;
		}

		switch(n) {
			case 0:
				ApplicationStateStack::getInstance().pop();
				break;
			case 1:
				while(ApplicationStateStack::getInstance().size() > 0) {
					ApplicationStateStack::getInstance().pop();
				}
				ApplicationStateStack::getInstance().push<TitleState>();
				break;
			case 2:
				SDL_Delay(100);
				Game::quit = true;
				break;
			default: break;
		}
	}

	if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
		Sound::Effect::play(Sound::Effect::back);
		ApplicationStateStack::getInstance().pop();
	}
}

void EndState::render() {
	m_cmdwin.draw();
}

