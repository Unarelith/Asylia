/*
 * =====================================================================================
 *
 *       Filename:  BattleState.cpp
 *
 *    Description:
 *
 *        Created:  22/04/2014 19:23:03
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/audio/AudioPlayer.hpp>

#include "ApplicationStateStack.hpp"
#include "BattleState.hpp"
#include "CharacterManager.hpp"
#include "EndState.hpp"
#include "EventListener.hpp"
#include "InfoWindow.hpp"
#include "Interface.hpp"
#include "ItemManager.hpp"
#include "ItemWindow.hpp"
#include "Keyboard.hpp"
#include "VictoryWindow.hpp"

BattleState::BattleState(Troop *troop, bool allowDefeat) {
	m_troop = troop;
	for(u8 i = 0 ; i < CharacterManager::getInstance().getPlayer()->teamSize() ; i++) {
		m_battle.addActor(CharacterManager::getInstance().getPlayer()->getTeamMember(i));
	}
	m_battle.addTroop(m_troop);

	m_currentPos = 0;
	m_arrowPos = 0;

	m_mode = Mode::Choice;

	m_itemwin.reset(new ItemWindow(0, 52, GameWindow::main->width(), 320 - 52, CharacterManager::getInstance().getPlayer()->inventory()));

	m_currentItem = nullptr;

	m_processingAction = false;

	m_gameoverAlpha = 1;

	m_allowDefeat = allowDefeat;

	m_victorywin.init(&m_battle);

	gk::AudioPlayer::playMusic("music-battle");
}

void BattleState::update() {
	if(m_mode == Mode::Choice) {
		m_battleChoicewin.update();

		if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
			gk::AudioPlayer::playSound("sound-confirm");
			switch(m_battleChoicewin.pos()) {
				case 0:
					m_mode = Mode::Action;
					m_currentPos = m_battle.getNextActorPair(1, -1).first;
					break;
				case 1:
					gk::AudioPlayer::playSound("sound-back");

					ApplicationStateStack::getInstance().pop();

					EventListener::addBattleResult(1); // Escape

					gk::AudioPlayer::playMusic("music-theme");
					break;
				default: break;
			}
		}
	}

	if(m_mode == Mode::Action) {
		m_battleActionwin.update();

		m_battle.getActor(m_currentPos)->blink();

		if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
			if(m_battleActionwin.disabled(m_battleActionwin.pos())) {
				gk::AudioPlayer::playSound("sound-blocked");
				return;
			}

			gk::AudioPlayer::playSound("sound-confirm");
			switch(m_battleActionwin.pos()) {
				case 0:
					m_mode = Mode::ChooseEnemyTarget;
					m_arrowPos = m_battle.getNextEnemyPair(1, -1).first;
					if(m_arrowPos >= (s8)m_battle.enemies().size()) {
						m_arrowPos = 0;
					}
					break;
				case 3:
					m_mode = Mode::ItemWin;
					m_itemwin->pos(0);
					break;
				default: break;
			}
		}

		if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
			gk::AudioPlayer::playSound("sound-back");
			if(m_currentPos == 0) {
				m_mode = Mode::Choice;
			} else {
				if(m_battle.getNextActorPair(-1, m_currentPos).second == nullptr) {
					m_currentPos = 0;
					m_mode = Mode::Choice;
				} else {
					m_currentPos--;
				}

				m_battle.popAction();
			}
		}
	}

	if(m_mode == Mode::ItemWin) {
		m_itemwin->update();

		if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
			gk::AudioPlayer::playSound("sound-confirm");
			m_currentItem = CharacterManager::getInstance().getPlayer()->inventory()->getItem(m_itemwin->pos());
		}

		if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
			gk::AudioPlayer::playSound("sound-back");
			m_mode = Mode::Action;
		}
	}

	if(m_mode == Mode::ChooseActorTarget) {
		m_battle.getActor(m_currentPos)->blink();

		if(Keyboard::isKeyPressedWithDelay(Keyboard::GameLeft, 150)) {
			gk::AudioPlayer::playSound("sound-move");

			m_arrowPos = m_battle.getNextActorPair(-1, m_arrowPos).first;

			if(m_arrowPos < 0) m_arrowPos = m_battle.getNextActorPair(-1, m_battle.actors().size()).first;
		}
		if(Keyboard::isKeyPressedWithDelay(Keyboard::GameRight, 150)) {
			gk::AudioPlayer::playSound("sound-move");

			m_arrowPos = m_battle.getNextActorPair(1, m_arrowPos).first;

			if(m_arrowPos >= (s16)m_battle.actors().size()) m_arrowPos = m_battle.getNextActorPair(1, -1).first;
		}

		if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
			gk::AudioPlayer::playSound("sound-back");
			m_mode = Mode::Action;
		}
	}

	if(m_mode == Mode::ChooseEnemyTarget) {
		m_battle.getActor(m_currentPos)->blink();

		if(Keyboard::isKeyPressedWithDelay(Keyboard::GameLeft, 200)) {
			gk::AudioPlayer::playSound("sound-move");

			m_arrowPos = m_battle.getNextEnemyPair(-1, m_arrowPos).first;

			if(m_arrowPos < 0) {
				m_arrowPos = m_battle.getNextEnemyPair(-1, m_battle.enemies().size()).first;
			}
		}
		else if(Keyboard::isKeyPressedWithDelay(Keyboard::GameRight, 200)) {
			gk::AudioPlayer::playSound("sound-move");

			m_arrowPos = m_battle.getNextEnemyPair(1, m_arrowPos).first;

			if(m_arrowPos >= (s16)m_battle.enemies().size()) {
				m_arrowPos = m_battle.getNextEnemyPair(1, -1).first;
			}
		}

		if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
			gk::AudioPlayer::playSound("sound-confirm");

			m_battle.pushAction(m_battle.getActor(m_currentPos), m_battle.getEnemy(m_arrowPos), ItemManager::getInstance().getSkill(0));
			m_arrowPos = 0;
			m_currentPos = m_battle.getNextActorPair(1, m_currentPos).first;
			if(m_currentPos >= (s8)m_battle.actors().size()) {
				m_currentPos = 0;
				m_mode = Mode::EnemyTurn;
			} else {
				m_mode = Mode::Action;
			}
		}

		if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
			gk::AudioPlayer::playSound("sound-back");
			m_mode = Mode::Action;
		}
	}

	if(m_mode == Mode::EnemyTurn) {
		m_battle.enemyTurn();
		m_battle.sortBattleActions();
		m_mode = Mode::ProcessActions;
	}

	if(m_mode == Mode::ProcessActions) {
		if(!m_processingAction) {
			u8 i = 0;
			for(auto &it : m_battle.actors()) {
				if(it.second->hp() == 0) i++;
			}

			if(i == m_battle.actors().size()) {
				m_mode = Mode::GameOver;
				return;
			}

			u8 j = 0;
			for(auto &it : m_battle.enemies()) {
				if(it.second->hp() == 0) j++;
			}

			if(j == m_battle.enemies().size()) {
				m_mode = Mode::Victory;
				return;
			}

			if(m_battle.actionStackEmpty()) {
				m_mode = Mode::Choice;
				return;
			}

			m_battle.processAction();

			m_processingAction = true;
		} else {
			m_battle.checkDead();
			m_battle.updateAction();
		}
	}

	if(m_mode == Mode::GameOver) {
		m_gameoverAlpha += 2;
		if((m_gameoverAlpha > 350 && Keyboard::isKeyPressed(Keyboard::GameAttack)) || (m_gameoverAlpha > 100 && m_allowDefeat)) {
			if(!m_allowDefeat) {
				ApplicationStateStack::getInstance().push<EndState>(true);
			} else {
				ApplicationStateStack::getInstance().pop();

				EventListener::addBattleResult(2); // Defeat
			}
		}
	}

	if(m_mode == Mode::Victory) {
		if(Keyboard::isKeyPressed(Keyboard::GameAttack)) {
			ApplicationStateStack::getInstance().pop();

			EventListener::addBattleResult(0); // Victory

			gk::AudioPlayer::playMusic("music-theme");
		}
	}
}

void BattleState::render() {
	if(m_mode != Mode::GameOver) {
		m_battle.renderBattleback();

		m_actorStatswin.drawEnemies(m_battle.enemies());

		if(m_mode == Mode::Choice) {
			m_battleChoicewin.draw();
		}

		if(m_mode == Mode::Action) {
			m_battleActionwin.draw(m_currentPos);
		}

		if(m_mode == Mode::ItemWin) {
			m_itemwin->draw();
		}

		if(m_mode == Mode::ChooseActorTarget) {
			m_battle.drawArrow(m_battle.getActor(m_arrowPos));
		}

		if(m_mode == Mode::ChooseEnemyTarget) {
			Enemy *enemy = m_battle.getEnemy(m_arrowPos);
			m_battle.drawArrow(enemy);
			m_infowin.drawTextCentered(enemy->name() + " [" + _t("HP") + ": " + std::to_string(enemy->hp()) + "/" + std::to_string(enemy->basehp()) + "]");
		}

		m_actorStatswin.drawActors(m_battle.actors());

		if(m_mode == Mode::ProcessActions) {
			if(m_processingAction) {
				if(m_battle.drawAction()) {
					m_processingAction = false;
					m_battle.popAction();
				}
			}
		}

		if(m_mode == Mode::Victory) {
			m_victorywin.draw();
		}
	} else {
		if(!m_allowDefeat) {
			if(m_gameoverAlpha < 256) m_gameover.setAlphaMod(m_gameoverAlpha);
			m_gameover.render();
			if(m_gameoverAlpha > 400) {
				Interface::defaultFont->print("Press A to continue", 3, 3, FONT_LARGE);
			}
		} else {
			m_battle.renderBattleback();

			m_actorStatswin.drawEnemies(m_battle.enemies());

			m_actorStatswin.drawActors(m_battle.actors());
		}
	}
}

