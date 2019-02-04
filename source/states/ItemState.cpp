/*
 * =====================================================================================
 *
 *       Filename:  ItemState.cpp
 *
 *    Description:
 *
 *        Created:  24/03/2014 22:26:14
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "CharacterManager.hpp"
#include "GameWindow.hpp"
#include "ItemState.hpp"
#include "Keyboard.hpp"
#include "Sound.hpp"
#include "ApplicationStateStack.hpp"

ItemState::ItemState(ApplicationState *parent) : ApplicationState(parent) {
	m_type = Type::Items;

	m_itemwin.reset(new ItemWindow(150, 52, GameWindow::main->width() - 150, GameWindow::main->height() - 52, CharacterManager::player->inventory(), 150, 0));
}

void ItemState::update() {
	m_itemwin->update();

	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		Sound::Effect::play(Sound::Effect::confirm);
	}

	if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
		Sound::Effect::play(Sound::Effect::back);
		ApplicationStateStack::getInstance().pop();
	}
}

void ItemState::render() {
	renderBackground();

	m_itemwin->draw();
}

