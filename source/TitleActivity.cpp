/*
 * =====================================================================================
 *
 *       Filename:  TitleActivity.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 17:20:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

TitleActivity::TitleActivity() {
	m_type = Type::TitleScreen;
	
	std::vector<std::string> choices;
	
	choices.push_back("New Game");
	choices.push_back("Continue");
	choices.push_back("Quit");
	
	m_background = new Image("graphics/interface/TitleScreen.jpg");
	
	m_cmdwin = new CommandWindow(192, choices);
	m_cmdwin->x(GameWindow::main->width() / 2 - m_cmdwin->width() / 2);
	m_cmdwin->y(GameWindow::main->height() / 2 + int(GameWindow::main->height() / 10));
	
	GameWindow::main->updateViewportPosition(0, 0);
}

TitleActivity::~TitleActivity() {
	
}

void TitleActivity::processInputs() {
	
}

void TitleActivity::update() {
	m_cmdwin->update();
	
	if(Keyboard::isKeyPressedWithDelay(Keyboard::GameAttack, 100)) {
		Sound::Effect::play(Sound::Effect::confirm);
		
		switch(m_cmdwin->pos()) {
			case 0:
				ActivityManager::activities.push(new MapActivity);
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

