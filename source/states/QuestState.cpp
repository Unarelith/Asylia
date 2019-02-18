/*
 * =====================================================================================
 *
 *       Filename:  QuestState.cpp
 *
 *    Description:
 *
 *        Created:  30/06/2014 18:28:01
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/audio/AudioPlayer.hpp>
#include <gk/core/input/GamePad.hpp>
#include <gk/core/ApplicationStateStack.hpp>

#include "CommandWindow.hpp"
#include "GameKey.hpp"
#include "InfoWindow.hpp"
#include "Player.hpp"
#include "QuestState.hpp"
#include "ResourceHelper.hpp"

QuestState::QuestState(ApplicationState *parent) : ApplicationState(parent) {
	m_mode = Mode::CategoryChoice;

	m_questCategorywin.columnMax(3);
	m_questCategorywin.addCommand("Quests_All");
	m_questCategorywin.addCommand("Quests_Current");
	m_questCategorywin.addCommand("Quests_Completed");

	m_questListwin.height(GameWindow::main->height() - 116);
}

void QuestState::update() {
	static bool s_load = true;

	if(m_mode == Mode::CategoryChoice) {
		m_questCategorywin.update();

		if(s_load || gk::GamePad::isKeyPressedOnce(GameKey::Left) || gk::GamePad::isKeyPressedOnce(GameKey::Right)) {
			s_load = false;

			m_questListwin.clear();
			m_currentQuest = nullptr;

			bool first = false;
			for(auto it : ResourceHelper::getPlayer()->quests()) {
				switch(m_questCategorywin.pos()) {
					case 0:
						if(!first) {
							m_currentQuest = it;
							first = true;
						}
						m_questListwin.addCommand(std::string("Quest") + std::to_string(it->id()));
						break;
					case 1:
						if(!it->completed()) {
							if(!first) {
								m_currentQuest = it;
								first = true;
							}
							m_questListwin.addCommand(std::string("Quest") + std::to_string(it->id()));
						}
						break;
					case 2:
						if(it->completed()) {
							if(!first) {
								m_currentQuest = it;
								first = true;
							}
							m_questListwin.addCommand(std::string("Quest") + std::to_string(it->id()));
						}
						break;
					default: break;
				}
			}
			m_questListwin.height(GameWindow::main->height() - 114);
		}

		if(gk::GamePad::isKeyPressedOnce(GameKey::A)) {
			gk::AudioPlayer::playSound("sound-confirm");

			m_mode = Mode::QuestChoice;
		}

		if(gk::GamePad::isKeyPressedOnce(GameKey::B)) {
			gk::AudioPlayer::playSound("sound-back");

			s_load = true;

			gk::ApplicationStateStack::getInstance().pop();
		}
	}
	else if(m_mode == Mode::QuestChoice) {
		m_questListwin.update();
		m_questInfowin.update();

		if(gk::GamePad::isKeyPressedOnce(GameKey::B)) {
			gk::AudioPlayer::playSound("sound-back");

			m_mode = Mode::CategoryChoice;
		}
	}
}

void QuestState::render() {
	if (m_parent && m_parent->parent())
		m_parent->parent()->render();

	m_questTitlewin.drawTextCentered(_t("Quests"));

	m_questCategorywin.draw(m_mode == Mode::CategoryChoice);
	m_questListwin.draw(m_mode == Mode::QuestChoice);

	m_questInfowin.draw(m_currentQuest);
}

