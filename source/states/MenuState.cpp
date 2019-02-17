/*
 * =====================================================================================
 *
 *       Filename:  MenuState.cpp
 *
 *    Description:
 *
 *        Created:  21/03/2014 18:23:30
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/audio/AudioPlayer.hpp>

#include "ApplicationStateStack.hpp"
#include "EndState.hpp"
#include "EquipState.hpp"
#include "GameWindow.hpp"
#include "ItemState.hpp"
#include "Keyboard.hpp"
#include "MenuState.hpp"
#include "QuestState.hpp"
#include "SettingsState.hpp"

MenuState::MenuState(ApplicationState *parent) : ApplicationState(parent) {
	m_type = Type::Menu;

	loadCommandWindow();

	m_actorChoicewin.reset(new ActorChoiceWindow(150, 0, GameWindow::main->width() - 150, GameWindow::main->height()));

	m_actorChoiceMode = false;
}

void MenuState::loadCommandWindow() {
	m_cmdwin.reset(new CommandWindow(150));

	m_cmdwin->addCommand("Items");
	m_cmdwin->addCommand("Skills", true);
	m_cmdwin->addCommand("Equip");
	m_cmdwin->addCommand("State", true);
	m_cmdwin->addCommand("Quests");
	m_cmdwin->addCommand("Save", true);
	m_cmdwin->addCommand("Settings");
	m_cmdwin->addCommand("Quit");
}

void MenuState::update() {
	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		if(m_cmdwin->disabled(m_cmdwin->pos())) {
			gk::AudioPlayer::playSound("sound-blocked");
		} else {
			gk::AudioPlayer::playSound("sound-confirm");

			if(m_actorChoiceMode) {
				m_actorChoiceMode = false;

				switch(m_cmdwin->pos()) {
					case 1: break;
					case 2:
						ApplicationStateStack::getInstance().push<EquipState>(m_actorChoicewin->pos(), this);
						break;
					case 3: break;
					default: break;
				}
			} else {
				switch(m_cmdwin->pos()) {
					case 0:
						ApplicationStateStack::getInstance().push<ItemState>(this);
						break;
					case 4:
						ApplicationStateStack::getInstance().push<QuestState>(this);
						break;
					case 5: break;
					case 6:
						ApplicationStateStack::getInstance().push<SettingsState>(this);
						break;
					case 7:
						ApplicationStateStack::getInstance().push<EndState>();
						break;
					default:
						m_actorChoiceMode = true;
						break;
				}
			}
		}
	}

	if(!m_actorChoiceMode) m_cmdwin->update();
	else m_actorChoicewin->update();

	if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
		gk::AudioPlayer::playSound("sound-back");
		if(!m_actorChoiceMode) ApplicationStateStack::getInstance().pop();
		else {
			m_actorChoiceMode = false;
			m_actorChoicewin->pos(0);
		}
	}
}

void MenuState::render() {
	if (m_parent)
		m_parent->render();

	m_cmdwin->draw(&ApplicationStateStack::getInstance().top() == this && !m_actorChoiceMode);

	if(m_actorChoiceMode) {
		m_actorChoicewin->draw();
	}
}

