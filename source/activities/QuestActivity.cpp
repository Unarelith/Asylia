/*
 * =====================================================================================
 *
 *       Filename:  QuestActivity.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  30/06/2014 18:28:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

QuestActivity::QuestActivity(Activity *parent) : Activity(parent) {
	m_mode = Mode::CategoryChoice;
	
	m_currentQuest = NULL;
	
	m_questTitlewin = new InfoWindow(0, 0, GameWindow::main->width(), 52);
	
	m_questCategorywin = new CommandWindow(0, 52, GameWindow::main->width(), true, true);
	m_questCategorywin->columnMax(3);
	m_questCategorywin->addCommand("Quests_All");
	m_questCategorywin->addCommand("Quests_Current");
	m_questCategorywin->addCommand("Quests_Completed");
	
	m_questListwin = new CommandWindow(0, 114, 200);
	m_questListwin->height(GameWindow::main->height() - 114);
}

QuestActivity::~QuestActivity() {
	delete m_questListwin;
	delete m_questCategorywin;
	
	delete m_questTitlewin;
}

void QuestActivity::update() {
	if(m_mode == Mode::CategoryChoice) {
		m_questCategorywin->update();
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
			Sound::Effect::play(Sound::Effect::confirm);
			
			m_mode = Mode::QuestChoice;
			
			m_questListwin->clear();
			for(auto it : CharacterManager::player->quests()) {
				m_questListwin->addCommand(std::string("quest") + to_string(it->id()) + "name");
			}
		}
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
			Sound::Effect::play(Sound::Effect::back);
			
			ActivityManager::pop();
		}
	}
	else if(m_mode == Mode::QuestChoice) {
		m_questListwin->update();
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
			Sound::Effect::play(Sound::Effect::back);
			
			m_mode = Mode::CategoryChoice;
		}
	}
}

void QuestActivity::render() {
	m_parent->renderBackground();
	
	m_questTitlewin->drawTextCentered(_t("Quests"));
	
	m_questCategorywin->draw(m_mode == Mode::CategoryChoice);
	m_questListwin->draw(m_mode == Mode::QuestChoice);
	
	m_questInfowin.draw(m_currentQuest);
}

