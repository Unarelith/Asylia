/*
 * =====================================================================================
 *
 *       Filename:  BattleAction.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/05/2014 14:02:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

BattleAction::BattleAction(Battler *actor, Battler *receiver, Item *item) {
	m_actor = actor;
	m_receiver = receiver;
	
	m_item = item;
	
	m_damages = -1;
}

BattleAction::~BattleAction() {
}

void BattleAction::process() {
	if(m_item->type() == Item::Type::Skill) {
		m_damages = m_actor->atk() + ((Skill*)(m_item))->atk() - m_receiver->def();
		if(m_damages < 0) m_damages = 0;
		m_receiver->hurt(m_damages);
	}
}

s16 dmgx = -1;
s16 dmgy = -1;
s8 dmgvx = 0;
s8 dmgvy = 0;
u16 dmgmvcount = 0;
bool BattleAction::drawDamages() {
	if(dmgx == -1 && dmgy == -1) {
		dmgx = m_receiver->image()->posRect().x + m_receiver->image()->posRect().w / 2 - 12;
		dmgy = m_receiver->image()->posRect().y + m_receiver->image()->posRect().h / 2 - 12;
		
		dmgvx = rand() % 2 * 2 - 1;
		dmgvy = rand() % 2 * 2 - 1;
		
		dmgmvcount = 0;
	}
	
	if(m_item->type() == Item::Type::Skill) {
		Interface::defaultFont->printDamages(m_damages, dmgx, dmgy, Color::red);
		
		dmgx += dmgvx;
		dmgy += dmgvy;
		
		dmgmvcount++;
	}
	
	if(dmgmvcount > 32) {
		dmgx = -1;
		dmgy = -1;
		return true;
	} else {
		return false;
	}
}

