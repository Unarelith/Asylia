/*
 * =====================================================================================
 *
 *       Filename:  TitleActivity.cpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 17:20:07
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

TitleActivity::TitleActivity() {
	m_type = Type::TitleScreen;

	m_background = new Image("graphics/interface/TitleScreen.jpg");

	m_cmdwin = new CommandWindow(192);
	m_cmdwin->addCommand("NewGame");
	m_cmdwin->addCommand("Continue", true);
	m_cmdwin->addCommand("Quit");

	m_cmdwin->x(GameWindow::main->width() / 2 - m_cmdwin->width() / 2);
	m_cmdwin->y(GameWindow::main->height() / 2 + int(GameWindow::main->height() / 10));

	Sound::Music::play(Sound::Music::title, -1);
}

TitleActivity::~TitleActivity() {
	delete m_cmdwin;
	delete m_background;
}

void TitleActivity::update() {
	m_cmdwin->update();

	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		if(m_cmdwin->disabled(m_cmdwin->pos())) {
			Sound::Effect::play(Sound::Effect::blocked);
			return;
		}

		Sound::Effect::play(Sound::Effect::confirm);

		switch(m_cmdwin->pos()) {
			case 0:
				ActivityManager::push(new MapActivity);
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

void TitleActivity::render() {
	m_background->renderCopy();
	m_cmdwin->draw();
}

