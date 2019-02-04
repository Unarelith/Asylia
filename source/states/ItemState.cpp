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
#include <gk/audio/AudioPlayer.hpp>

#include "ApplicationStateStack.hpp"
#include "CharacterManager.hpp"
#include "GameWindow.hpp"
#include "ItemState.hpp"
#include "Keyboard.hpp"

ItemState::ItemState(ApplicationState *parent) : ApplicationState(parent) {
	m_type = Type::Items;

	m_itemwin.reset(new ItemWindow(150, 52, GameWindow::main->width() - 150, GameWindow::main->height() - 52, CharacterManager::player->inventory(), 150, 0));
}

void ItemState::update() {
	m_itemwin->update();

	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		gk::AudioPlayer::playSound("sound-confirm");
	}

	if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
		gk::AudioPlayer::playSound("sound-back");
		ApplicationStateStack::getInstance().pop();
	}
}

void ItemState::render() {
	renderBackground();

	m_itemwin->draw();
}

