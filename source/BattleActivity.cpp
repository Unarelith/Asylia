/*
 * =====================================================================================
 *
 *       Filename:  BattleActivity.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/04/2014 19:23:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

BattleActivity::BattleActivity() {
	m_type = Type::BattleAct;
	
	m_battle = BattleManager::battles[0];
	
	m_currentPos = 0;
	m_arrowPos = 0;
	
	m_mode = Mode::Choice;
	
	m_infowin = new InfoWindow(0, 0, GameWindow::main->width(), 52);
	
	m_currentItem = NULL;
	
	m_processingAction = false;
	
	Sound::Music::play(Sound::Music::battle, -1);
}

BattleActivity::~BattleActivity() {
	delete m_infowin;
}

void BattleActivity::update() {
	if(m_mode == Mode::Choice) {
		m_battleChoicewin.update();
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
			Sound::Effect::play(Sound::Effect::confirm);
			switch(m_battleChoicewin.pos()) {
				case 0:
					m_mode = Mode::Action;
					break;
				case 1:
					Sound::Effect::play(Sound::Effect::back);
					ActivityManager::pop();
					Sound::Music::halt();
					Sound::Music::play(Sound::Music::theme, -1);
					break;
				default: break;
			}
		}
	}
	
	if(m_mode == Mode::Action) {
		while(m_battle->actors()[m_currentPos++]->hp() == 0) {
			if(m_currentPos >= (s8)m_battle->actors().size()) {
				m_mode = Mode::EnemyTurn;
				break;
			}
		}
		m_currentPos--;
		
		m_battleActionwin.update();
		
		m_battle->actors()[m_currentPos]->blink();
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
			Sound::Effect::play(Sound::Effect::confirm);
			switch(m_battleActionwin.pos()) {
				case 0:
					m_mode = Mode::ChooseEnemyTarget;
					m_arrowPos = 0;
					break;
				default: break;
			}
		}
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
			Sound::Effect::play(Sound::Effect::back);
			if(m_currentPos == 0) {
				m_mode = Mode::Choice;
			} else {
				while(m_battle->actors()[m_currentPos--]->hp() == 0) {
					if(m_currentPos < 0) {
						m_mode = Mode::Choice;
						break;
					}
				}
				
				m_battle->popAction();
			}
		}
	}
	
	if(m_mode == Mode::ChooseActorTarget) {
		m_battle->actors()[m_currentPos]->blink();
		
		if(Keyboard::isKeyPressedWithDelay(Keyboard::GameLeft, 150)) {
			Sound::Effect::play(Sound::Effect::move);
			
			while(m_battle->actors()[m_arrowPos--]->hp() == 0) {
				if(m_arrowPos < 0) m_arrowPos = m_battle->actors().size() - 1;
			}
			
			if(m_arrowPos < 0) m_arrowPos = m_battle->actors().size() - 1;
		}
		if(Keyboard::isKeyPressedWithDelay(Keyboard::GameRight, 150)) {
			Sound::Effect::play(Sound::Effect::move);
			
			while(m_battle->actors()[m_arrowPos++]->hp() == 0) {
				if(m_arrowPos > (s8)m_battle->actors().size()) m_arrowPos = 0;
			}
			
			if(m_arrowPos >= (s16)m_battle->actors().size()) m_arrowPos = 0;
		}
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
			Sound::Effect::play(Sound::Effect::back);
			m_mode = Mode::Action;
		}
	}
	
	if(m_mode == Mode::ChooseEnemyTarget) {
		m_battle->actors()[m_currentPos]->blink();
		
		if(Keyboard::isKeyPressedWithDelay(Keyboard::GameLeft, 150)) {
			Sound::Effect::play(Sound::Effect::move);
			
			while(m_battle->enemies()[m_arrowPos--]->hp() == 0) {
				if(m_arrowPos < 0) m_arrowPos = m_battle->enemies().size() - 1;
			}
			
			if(m_arrowPos < 0) m_arrowPos = m_battle->enemies().size() - 1;
		}
		else if(Keyboard::isKeyPressedWithDelay(Keyboard::GameRight, 150)) {
			Sound::Effect::play(Sound::Effect::move);
			
			while(m_battle->enemies()[m_arrowPos++]->hp() == 0) {
				if(m_arrowPos >= (s8)m_battle->enemies().size()) m_arrowPos = 0;
			}
			
			if(m_arrowPos >= (s16)m_battle->enemies().size()) m_arrowPos = 0;
		}
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
			Sound::Effect::play(Sound::Effect::confirm);
			
			m_battle->pushAction(m_battle->actors()[m_currentPos], m_battle->enemies()[m_arrowPos], ItemManager::skills[0]);
			m_arrowPos = 0;
			m_currentPos++;
			if(m_currentPos >= (s8)m_battle->actors().size()) {
				m_currentPos = 0;
				m_mode = Mode::EnemyTurn;
			} else {
				m_mode = Mode::Action;
			}
		}
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
			Sound::Effect::play(Sound::Effect::back);
			m_mode = Mode::Action;
		}
	}
	
	if(m_mode == Mode::EnemyTurn) {
		m_battle->enemyTurn();
		m_mode = Mode::ProcessActions;
	}
	
	if(m_mode == Mode::ProcessActions) {
		if(m_battle->actionStackEmpty()) {
			m_mode = Mode::Choice;
			return;
		}
		
		if(!m_processingAction) {
			m_battle->processAction();
			m_processingAction = true;
		} else {
			m_battle->checkDead();
		}
	}
}

void BattleActivity::render() {
	m_battle->renderBattleback();
	
	m_actorStatswin.drawEnemies(m_battle->enemies());
	
	if(m_mode == Mode::Choice) {
		m_battleChoicewin.draw();
	}
	else if(m_mode == Mode::Action) {
		m_battleActionwin.draw(m_currentPos);
	}
	else if(m_mode == Mode::ChooseActorTarget) {
		m_battle->drawArrow(m_battle->actors()[m_arrowPos]);
	}
	else if(m_mode == Mode::ChooseEnemyTarget) {
		m_battle->drawArrow(m_battle->enemies()[m_arrowPos]);
		m_infowin->drawTextCentered(m_battle->enemies()[m_arrowPos]->name());
	}
	
	m_actorStatswin.drawActors(m_battle->actors());
	
	if(m_mode == Mode::ProcessActions) {
		if(m_processingAction) {
			if(m_battle->drawAction()) {
				m_processingAction = false;
				m_battle->popAction();
			}
		}
	}
}

