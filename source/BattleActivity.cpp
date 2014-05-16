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
	
	m_battle = new Battle(*BattleManager::battles[0]);
	
	m_currentPos = 0;
	m_arrowPos = 0;
	
	m_mode = Mode::Choice;
	
	m_infowin = new InfoWindow(0, 0, GameWindow::main->width(), 52);
	
	m_currentItem = NULL;
	
	m_processingAction = false;
	
	m_gameover = new Image("graphics/interface/Gameover.jpg");
	m_gameoverAlpha = 1;
	
	//m_victoryWindow = new InfoWindow(GameWindow::main->width() / 2 - 128, GameWindow::main->height() / 2 - 96, 256, 192);
	
	Sound::Music::play(Sound::Music::battle, -1);
}

BattleActivity::~BattleActivity() {
	delete m_infowin;
	
	delete m_battle;
}

void BattleActivity::update() {
	if(m_mode == Mode::Choice) {
		m_battleChoicewin.update();
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
			Sound::Effect::play(Sound::Effect::confirm);
			switch(m_battleChoicewin.pos()) {
				case 0:
					m_mode = Mode::Action;
					m_currentPos = m_battle->getNextActorPair(1, -1).first;
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
		m_battleActionwin.update();
		
		m_battle->getActor(m_currentPos)->blink();
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
			Sound::Effect::play(Sound::Effect::confirm);
			switch(m_battleActionwin.pos()) {
				case 0:
					m_mode = Mode::ChooseEnemyTarget;
					m_arrowPos = m_battle->getNextEnemyPair(1, -1).first;
					if(m_arrowPos >= (s8)m_battle->enemies().size()) {
						m_arrowPos = 0;
					}
					break;
				default: break;
			}
		}
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
			Sound::Effect::play(Sound::Effect::back);
			if(m_currentPos == 0) {
				m_mode = Mode::Choice;
			} else {
				if(m_battle->getNextActorPair(-1, m_currentPos).second == NULL) {
					m_currentPos = 0;
					m_mode = Mode::Choice;
				}
				
				m_battle->popAction();
			}
		}
	}
	
	if(m_mode == Mode::ChooseActorTarget) {
		m_battle->getActor(m_currentPos)->blink();
		
		if(Keyboard::isKeyPressedWithDelay(Keyboard::GameLeft, 150)) {
			Sound::Effect::play(Sound::Effect::move);
			
			m_arrowPos = m_battle->getNextActorPair(-1, m_arrowPos).first;
			
			if(m_arrowPos < 0) m_arrowPos = m_battle->getNextActorPair(-1, m_battle->actors().size()).first;
		}
		if(Keyboard::isKeyPressedWithDelay(Keyboard::GameRight, 150)) {
			Sound::Effect::play(Sound::Effect::move);
			
			m_arrowPos = m_battle->getNextActorPair(1, m_arrowPos).first;
			
			if(m_arrowPos >= (s16)m_battle->actors().size()) m_arrowPos = m_battle->getNextActorPair(1, -1).first;
		}
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
			Sound::Effect::play(Sound::Effect::back);
			m_mode = Mode::Action;
		}
	}
	
	if(m_mode == Mode::ChooseEnemyTarget) {
		m_battle->getActor(m_currentPos)->blink();
		
		if(Keyboard::isKeyPressedWithDelay(Keyboard::GameLeft, 200)) {
			Sound::Effect::play(Sound::Effect::move);
			
			m_arrowPos = m_battle->getNextEnemyPair(-1, m_arrowPos).first;
			
			if(m_arrowPos < 0) {
				m_arrowPos = m_battle->getNextEnemyPair(-1, m_battle->enemies().size()).first;
			}
		}
		else if(Keyboard::isKeyPressedWithDelay(Keyboard::GameRight, 200)) {
			Sound::Effect::play(Sound::Effect::move);
			
			m_arrowPos = m_battle->getNextEnemyPair(1, m_arrowPos).first;
			
			if(m_arrowPos >= (s16)m_battle->enemies().size()) {
				m_arrowPos = m_battle->getNextEnemyPair(1, -1).first;
			}
		}
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
			Sound::Effect::play(Sound::Effect::confirm);
			
			m_battle->pushAction(m_battle->getActor(m_currentPos), m_battle->getEnemy(m_arrowPos), ItemManager::skills[0]);
			m_arrowPos = 0;
			m_currentPos = m_battle->getNextActorPair(1, m_currentPos).first;
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
			u8 i = 0;
			for(auto &it : m_battle->actors()) {
				if(it.second->hp() == 0) i++;
			}
			
			u8 j = 0;
			for(auto &it : m_battle->enemies()) {
				if(it.second->hp() == 0) j++;
			}
			
			if(i == m_battle->actors().size()) {
				m_mode = Mode::GameOver;
				return;
			}
			
			if(j == m_battle->enemies().size()) {
				m_mode = Mode::Victory;
				DialogActivity *dialog = ActivityManager::newDialogWithParent(this);
				dialog->addMessage("You win! 999999 exp 999ø");
				return;
			}
			
			m_battle->processAction();
			
			m_processingAction = true;
		} else {
			m_battle->checkDead();
		}
	}
	
	if(m_mode == Mode::GameOver) {
		m_gameoverAlpha += 2;
		if(m_gameoverAlpha < 256) m_gameover->setAlphaMod(m_gameoverAlpha);
		if(m_gameoverAlpha > 350 && Keyboard::isKeyPressed(Keyboard::GameAttack)) {
			ActivityManager::push(new EndActivity(true));
		}
	}
	
	if(m_mode == Mode::Victory) {
		ActivityManager::pop();
	}
}

void BattleActivity::render() {
	if(m_mode != Mode::GameOver) {
		m_battle->renderBattleback();
		
		m_actorStatswin.drawEnemies(m_battle->enemies());
		
		if(m_mode == Mode::Choice) {
			m_battleChoicewin.draw();
		}
		else if(m_mode == Mode::Action) {
			m_battleActionwin.draw(m_currentPos);
		}
		else if(m_mode == Mode::ChooseActorTarget) {
			m_battle->drawArrow(m_battle->getActor(m_arrowPos));
		}
		else if(m_mode == Mode::ChooseEnemyTarget) {
			Enemy *enemy = m_battle->getEnemy(m_arrowPos);
			m_battle->drawArrow(enemy);
			m_infowin->drawTextCentered(enemy->name() + " [" + _t("HP") + ": " + to_string(enemy->hp()) + "/" + to_string(enemy->basehp()) + "]");
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
	} else {
		m_gameover->render();
		if(m_gameoverAlpha > 400) {
			Interface::defaultFont->print("Press A to continue", 3, 3, FONT_LARGE);
		}
	}
}

