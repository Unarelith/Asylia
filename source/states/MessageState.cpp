/*
 * =====================================================================================
 *
 *       Filename:  MessageState.cpp
 *
 *    Description:
 *
 *        Created:  21/03/2014 18:22:38
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/audio/AudioPlayer.hpp>
#include <gk/core/input/GamePad.hpp>
#include <gk/core/ApplicationStateStack.hpp>

#include "Config.hpp"
#include "EventListener.hpp"
#include "GameKey.hpp"
#include "Map.hpp"
#include "MessageState.hpp"
#include "ResourceHelper.hpp"

MessageState::MessageState(const std::string &message, gk::ApplicationState *parent) : gk::ApplicationState(parent) {
	m_parent = parent;
	if(m_parent == nullptr) {
		m_parent = &gk::ApplicationStateStack::getInstance().top();
	}

	m_txtwin.reset(new TextWindow(40, SCREEN_HEIGHT - SCREEN_HEIGHT / 3 - 20, SCREEN_WIDTH - 80, SCREEN_HEIGHT / 3));

	m_cmdwin.reset(new CommandWindow(m_txtwin->x(), 0, 150, 0));

	m_message = message;
}

void MessageState::updateCmdwinSize() {
	// FIXME
	// u16 sizeMax = 0;
	// for(auto &it : m_cmdwin->commands()) {
	// 	if(it.first.size() > sizeMax) sizeMax = it.first.size();
	// }
    //
	// m_cmdwin->setWidth(sizeMax * 20 + 40);
	// m_cmdwin->setHeight(m_cmdwin->commands().size() * 32 + 32);
	// m_cmdwin->setY(m_txtwin->y() - m_cmdwin->height());
}

void MessageState::update() {
	if(m_cmdwin->commands().size() > 0) {
		m_cmdwin->update();
	}

	if(gk::GamePad::isKeyPressedOnce(GameKey::A)) {
		if(m_cmdwin->commands().size() > 0) {
			gk::AudioPlayer::playSound("sound-confirm");

			EventListener::addMessageStateAction(m_cmdwin->pos());
		}

		gk::ApplicationStateStack::getInstance().pop();
		ResourceHelper::getCurrentMap()->updateEventsActions();
	}
}

void MessageState::render() {
	// FIXME
	// if (m_parent)
	// 	m_parent->render();

	if(m_cmdwin->commands().size() > 0) {
		m_cmdwin->draw();
	}

	// FIXME
	// m_txtwin->draw(m_message);
}

