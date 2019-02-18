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
#include <gk/core/input/GamePad.hpp>
#include <gk/core/ApplicationStateStack.hpp>

#include "GameKey.hpp"
#include "GameWindow.hpp"
#include "ItemState.hpp"
#include "Player.hpp"
#include "ResourceHelper.hpp"

ItemState::ItemState(gk::ApplicationState *parent) : gk::ApplicationState(parent) {
	m_itemwin.reset(new ItemWindow(150, 52, GameWindow::main->width() - 150, GameWindow::main->height() - 52, ResourceHelper::getPlayer()->inventory(), 150, 0));
}

void ItemState::update() {
	m_itemwin->update();

	if(gk::GamePad::isKeyPressedOnce(GameKey::A)) {
		gk::AudioPlayer::playSound("sound-confirm");
	}

	if(gk::GamePad::isKeyPressedOnce(GameKey::B)) {
		gk::AudioPlayer::playSound("sound-back");
		m_stateStack->pop();
	}
}

void ItemState::render() {
	if (m_parent)
		m_parent->render();

	m_itemwin->draw();
}

