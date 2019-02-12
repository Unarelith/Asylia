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

#include "ApplicationStateStack.hpp"
#include "EventListener.hpp"
#include "GameWindow.hpp"
#include "Keyboard.hpp"
#include "MapManager.hpp"
#include "MessageState.hpp"

MessageState::MessageState(const std::string &message, ApplicationState *parent) : ApplicationState(parent) {
	m_type = Type::Message;

	m_parent = parent;
	if(m_parent == nullptr) {
		m_parent = &ApplicationStateStack::getInstance().top();
	}

	m_txtwin.reset(new TextWindow(40, GameWindow::main->height() - GameWindow::main->height() / 3 - 20, GameWindow::main->width() - 80, GameWindow::main->height() / 3));

	m_cmdwin.reset(new CommandWindow(m_txtwin->x(), 0, 150, 0));

	m_message = message;
}

void MessageState::updateCmdwinSize() {
	u16 sizeMax = 0;
	for(auto &it : m_cmdwin->commands()) {
		if(it.first.size() > sizeMax) sizeMax = it.first.size();
	}

	m_cmdwin->width(sizeMax * 20 + 40);
	m_cmdwin->height(m_cmdwin->commands().size() * 32 + 32);
	m_cmdwin->y(m_txtwin->y() - m_cmdwin->height());
}

void MessageState::update() {
	if(m_cmdwin->commands().size() > 0) {
		m_cmdwin->update();
	}

	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		if(m_cmdwin->commands().size() > 0) {
			gk::AudioPlayer::playSound("sound-confirm");

			EventListener::addMessageStateAction(m_cmdwin->pos());
		}

		ApplicationStateStack::getInstance().pop();
		MapManager::getInstance().getCurrentMap()->updateEventsActions();
	}
}

void MessageState::render() {
	renderBackground();

	if(m_cmdwin->commands().size() > 0) {
		m_cmdwin->draw();
	}

	m_txtwin->draw(m_message);
}

