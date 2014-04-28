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
				default: break;
			}
		}
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
			Sound::Effect::play(Sound::Effect::back);
			ActivityManager::pop();
			Sound::Music::halt();
			Sound::Music::play(Sound::Music::theme, -1);
		}
	}
	else if(m_mode == Mode::Action) {
		m_battleActionwin.update();
		
		m_battle->actors()[m_currentPos]->image()->setAlphaMod(abs(int(SDL_GetTicks() / 4 % 255 - 128)) + 127);
		
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
			m_mode = Mode::Choice;
		}
	}
	else if(m_mode == Mode::ChooseActorTarget) {
		if(Keyboard::isKeyPressedWithDelay(Keyboard::GameLeft, 150)) {
			Sound::Effect::play(Sound::Effect::move);
			m_arrowPos--;
			if(m_arrowPos < 0) m_arrowPos = m_battle->actors().size() - 1;
		}
		if(Keyboard::isKeyPressedWithDelay(Keyboard::GameRight, 150)) {
			Sound::Effect::play(Sound::Effect::move);
			m_arrowPos++;
			if(m_arrowPos >= (s16)m_battle->actors().size()) m_arrowPos = 0;
		}
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
			Sound::Effect::play(Sound::Effect::back);
			m_mode = Mode::Action;
		}
	}
	else if(m_mode == Mode::ChooseEnemyTarget) {
		if(Keyboard::isKeyPressedWithDelay(Keyboard::GameLeft, 150)) {
			Sound::Effect::play(Sound::Effect::move);
			m_arrowPos--;
			if(m_arrowPos < 0) m_arrowPos = m_battle->enemies().size() - 1;
		}
		if(Keyboard::isKeyPressedWithDelay(Keyboard::GameRight, 150)) {
			Sound::Effect::play(Sound::Effect::move);
			m_arrowPos++;
			if(m_arrowPos >= (s16)m_battle->enemies().size()) m_arrowPos = 0;
		}
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
			Sound::Effect::play(Sound::Effect::back);
			m_mode = Mode::Action;
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
}

