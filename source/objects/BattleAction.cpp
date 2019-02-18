/*
 * =====================================================================================
 *
 *       Filename:  BattleAction.cpp
 *
 *    Description:
 *
 *        Created:  11/05/2014 14:02:21
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "BattleAction.hpp"
#include "Font.hpp"
#include "ResourceHelper.hpp"

BattleAction::BattleAction(Battler *actor, Battler *receiver, Item *item) {
	m_actor = actor;
	m_receiver = receiver;

	m_item = item;

	m_damages = -1;

	m_variance = 0.20;

	m_animationAtEnd = false;

	m_dmgy = 0;
	m_dmgvy = 0;
	m_dmgmvcount = 0;
}

BattleAction::~BattleAction() {
}

void BattleAction::process() {
	if(m_actor->hp() == 0) return;
	if(!m_receiver) return;

	if(m_item->type() == Item::Type::Skill) {
		m_damages = (m_actor->totalAtk() + ((Skill*)(m_item))->atk()) * 2 - m_receiver->def();
		if(m_damages <= 0) m_damages = 1;
		m_damages += (rand() % (int)ceil(m_variance * m_damages * 2)) - m_variance * m_damages;
		if(m_damages <= 0) m_damages = 1;
		m_receiver->hurt(m_damages);
	}
}

void BattleAction::updateDamages() {
	if(m_item->battleAnimation()->animationAtEnd(0)) {
		m_dmgy = m_receiver->image()->posRect().y + m_receiver->image()->height() / 2 - 8;
	}

	if(m_animationAtEnd) {
		if(m_dmgmvcount < 8) {
			m_dmgvy = -2;
		}
		else if(m_dmgmvcount < 30) {
			m_dmgvy = 3;
		} else {
			m_animationAtEnd = false;
			m_dmgy = 0;
			m_dmgvy = 0;
			m_dmgmvcount = 0;
		}

		m_dmgy += m_dmgvy;

		m_dmgmvcount += abs(m_dmgvy);

	}
}

bool BattleAction::drawDamages() {
	if(m_actor->hp() == 0) return true;
	if(!m_receiver) return true;

	if(m_item->battleAnimation()->animationAtEnd(0)) {
		m_item->battleAnimation()->stopAnimation(0);
		m_item->battleAnimation()->resetAnimation(0);

		m_animationAtEnd = true;

	} else {
		if(!m_animationAtEnd) m_item->battleAnimation()->play(m_receiver);
	}

	if(m_animationAtEnd) {
		if(m_dmgmvcount >= 30) {
			return true;
		}

		u16 dmgx = m_receiver->image()->posRect().x + m_receiver->image()->posRect().w / 2 - log10(m_damages + 10) * 9 / 2;
		ResourceHelper::getFont("default").printDamages(m_damages, dmgx, m_dmgy - 8, gk::Color(255, 42, 36));
	}

	return false;
}

