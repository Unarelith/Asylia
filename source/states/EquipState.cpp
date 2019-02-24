/*
 * =====================================================================================
 *
 *       Filename:  EquipState.cpp
 *
 *    Description:
 *
 *        Created:  10/04/2014 19:51:12
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/audio/AudioPlayer.hpp>
#include <gk/core/input/GamePad.hpp>
#include <gk/core/ApplicationStateStack.hpp>

#include "Config.hpp"
#include "EquipState.hpp"
#include "GameKey.hpp"
#include "MenuState.hpp"
#include "Player.hpp"
#include "ResourceHelper.hpp"

EquipState::EquipState(u8 actorPos, ApplicationState *parent) : ApplicationState(parent) {
	m_itemMode = false;

	m_actor = ResourceHelper::getPlayer()->getTeamMember(actorPos);

	m_equipment = ResourceHelper::getPlayer()->getTeamMember(actorPos)->equipment();

	m_statswin.reset(new EquipStatsWindow(m_actor));
	m_choicewin.reset(new EquipChoiceWindow(m_equipment));

	m_itemwin.reset(new ItemWindow(150, 52 + (SCREEN_HEIGHT - 52) / 2, SCREEN_WIDTH - 150, (SCREEN_HEIGHT - 52) / 2, ResourceHelper::getPlayer()->inventory(), 150, 0));
	m_itemwin->changeSet(0, 0, m_equipment);
}

void EquipState::update() {
	// FIXME: SLOW?? //
	if(m_choicewin->pos() == 0) {
		m_itemwin->changeSet(m_choicewin->pos(), m_choicewin->pos(), m_equipment);
	} else {
		m_itemwin->changeSet(m_choicewin->pos(), m_choicewin->pos() - 1, m_equipment);
	}

	if(m_itemMode) m_itemwin->update();
	else m_choicewin->update();

	if(gk::GamePad::isKeyPressedOnce(GameKey::A)) {
		if(m_itemMode) {
			gk::AudioPlayer::playSound("sound-confirm");

			// m_choicewin->setCursorVisible(true);
			m_itemwin->setCursorVisible(false);

			Item *currentItem = m_itemwin->currentItem();
			if(m_choicewin->pos() == 0) {
				if(currentItem) m_equipment->equipWeapon((Weapon*)currentItem);
				else m_equipment->unequipWeapon();
			} else {
				if(currentItem) m_equipment->equipArmor((Armor*)currentItem);
				else m_equipment->unequipArmor(m_choicewin->pos() - 1);
			}

			m_itemMode = false;
			m_itemwin->pos(0);
			m_itemwin->update();
		}
		else if(m_itemwin->itemMax() == 0) {
			gk::AudioPlayer::playSound("sound-blocked");
		} else {
			gk::AudioPlayer::playSound("sound-confirm");

			m_itemMode = true;

			// m_choicewin->setCursorVisible(false);
			m_itemwin->setCursorVisible(true);
		}
	}

	if(gk::GamePad::isKeyPressedOnce(GameKey::B)) {
		gk::AudioPlayer::playSound("sound-back");
		if(m_itemMode) {
			m_itemMode = false;
			m_itemwin->pos(0);
			m_itemwin->update();
			m_itemwin->setCursorVisible(false);

			// m_choicewin->setCursorVisible(true);
		} else {
			gk::ApplicationStateStack::getInstance().pop();
			((MenuState&)gk::ApplicationStateStack::getInstance().top()).actorChoiceModeOn();
		}
	}
}

void EquipState::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	if (m_parent)
		target.draw(*m_parent, states);

	if(m_itemMode) {
		// m_statswin->draw(m_itemwin->currentItem());
		target.draw(*m_statswin, states);
	}
	else {
		// m_statswin->draw();
		target.draw(*m_statswin, states);
	}

	// m_choicewin->draw(!m_itemMode);
	// m_itemwin->draw(m_itemMode, m_itemMode);
	target.draw(*m_choicewin, states);
	target.draw(*m_itemwin, states);
}

