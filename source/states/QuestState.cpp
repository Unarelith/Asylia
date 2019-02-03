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
#include "CharacterManager.hpp"
#include "CommandWindow.hpp"
#include "GameWindow.hpp"
#include "InfoWindow.hpp"
#include "Keyboard.hpp"
#include "QuestState.hpp"
#include "Sound.hpp"
#include "StateManager.hpp"

QuestState::QuestState(ApplicationState *parent) : ApplicationState(parent) {
	m_mode = Mode::CategoryChoice;

	m_currentQuest = nullptr;

	m_questTitlewin = new InfoWindow(0, 0, GameWindow::main->width(), 52);

	m_questCategorywin = new CommandWindow(0, 52, GameWindow::main->width(), true, true);
	m_questCategorywin->columnMax(3);
	m_questCategorywin->addCommand("Quests_All");
	m_questCategorywin->addCommand("Quests_Current");
	m_questCategorywin->addCommand("Quests_Completed");

	m_questListwin = new CommandWindow(0, 116, 200);
	m_questListwin->height(GameWindow::main->height() - 116);
}

QuestState::~QuestState() {
	delete m_questListwin;
	delete m_questCategorywin;

	delete m_questTitlewin;
}

void QuestState::update() {
	static bool s_load = true;

	if(m_mode == Mode::CategoryChoice) {
		m_questCategorywin->update();

		if(s_load || Keyboard::isKeyPressedOnce(Keyboard::GameLeft) || Keyboard::isKeyPressedOnce(Keyboard::GameRight)) {
			s_load = false;

			m_questListwin->clear();
			m_currentQuest = nullptr;

			bool first = false;
			for(auto it : CharacterManager::player->quests()) {
				switch(m_questCategorywin->pos()) {
					case 0:
						if(!first) {
							m_currentQuest = it;
							first = true;
						}
						m_questListwin->addCommand(std::string("Quest") + std::to_string(it->id()));
						break;
					case 1:
						if(!it->completed()) {
							if(!first) {
								m_currentQuest = it;
								first = true;
							}
							m_questListwin->addCommand(std::string("Quest") + std::to_string(it->id()));
						}
						break;
					case 2:
						if(it->completed()) {
							if(!first) {
								m_currentQuest = it;
								first = true;
							}
							m_questListwin->addCommand(std::string("Quest") + std::to_string(it->id()));
						}
						break;
					default: break;
				}
			}
			m_questListwin->height(GameWindow::main->height() - 114);
		}

		if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
			Sound::Effect::play(Sound::Effect::confirm);

			m_mode = Mode::QuestChoice;
		}

		if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
			Sound::Effect::play(Sound::Effect::back);

			s_load = true;

			StateManager::pop();
		}
	}
	else if(m_mode == Mode::QuestChoice) {
		m_questListwin->update();
		m_questInfowin.update();

		if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
			Sound::Effect::play(Sound::Effect::back);

			m_mode = Mode::CategoryChoice;
		}
	}
}

void QuestState::render() {
	m_parent->renderBackground();

	m_questTitlewin->drawTextCentered(_t("Quests"));

	m_questCategorywin->draw(m_mode == Mode::CategoryChoice);
	m_questListwin->draw(m_mode == Mode::QuestChoice);

	m_questInfowin.draw(m_currentQuest);
}

