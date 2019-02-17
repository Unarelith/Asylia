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
#include <gk/core/ApplicationStateStack.hpp>

#include "GameWindow.hpp"
#include "ItemState.hpp"
#include "Keyboard.hpp"
#include "Player.hpp"
#include "ResourceHelper.hpp"

ItemState::ItemState(gk::ApplicationState *parent) : gk::ApplicationState(parent) {
	m_itemwin.reset(new ItemWindow(150, 52, GameWindow::main->width() - 150, GameWindow::main->height() - 52, ResourceHelper::getPlayer()->inventory(), 150, 0));
}

void ItemState::update() {
	m_itemwin->update();

	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		gk::AudioPlayer::playSound("sound-confirm");
	}

	if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
		gk::AudioPlayer::playSound("sound-back");
		m_stateStack->pop();
	}
}

void ItemState::render() {
	if (m_parent)
		m_parent->render();

	m_itemwin->draw();
}

