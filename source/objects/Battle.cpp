/*
 * =====================================================================================
 *
 *       Filename:  Battle.cpp
 *
 *    Description:
 *
 *        Created:  23/04/2014 18:05:00
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <algorithm>

#include "Battle.hpp"
#include "Map.hpp"
#include "ResourceHelper.hpp"

Battle::Battle(const Battle &battle) {
	for(auto &it : battle.m_actors) {
		m_actors.push_back(it);
	}

	for(auto &it : battle.m_enemies) {
		m_enemies.emplace_back(it.first, it.second);
	}

	m_actorsCount = battle.m_actorsCount;
	m_enemiesCount = battle.m_enemiesCount;

	m_battleback = battle.m_battleback;

	m_exp = battle.m_exp;
	m_gold = battle.m_gold;
}

Battle::Battle() {
	m_actorsCount = 0;
	m_enemiesCount = 0;

	m_battleback = &ResourceHelper::getCurrentMap()->battleback();

	m_exp = 0;
	m_gold = 0;
}

Battle::~Battle() {
	while(m_enemies.size() != 0) {
		delete m_enemies.back().second;
		m_enemies.pop_back();
	}
}

void Battle::addTroop(Troop *troop) {
	for(u8 i = 0 ; i < troop->size() ; i++) {
		addEnemy(troop->getEnemy(i), troop->getEnemyX(i), troop->getEnemyY(i));
	}
	if(troop->isBattlebackLoaded()) m_battleback = &troop->battleback();
}

void Battle::addEnemy(Enemy *enemy, s16 x, s16 y) {
	m_enemies.emplace_back(m_enemiesCount, enemy);

	m_enemies.back().second->setPosition(x, y);

	m_exp += m_enemies.back().second->expGivenIfKilled();
	m_gold += m_enemies.back().second->goldGivenIfKilled();

	m_enemiesCount++;
}

void Battle::drawArrow(Battler *battler) {
	s16 x, y;
	u16 width, height;

	width = battler->image().width();
	height = battler->image().height();

	x = battler->image().getPosition().x + width / 2 - 16;
	y = battler->image().getPosition().y + height / 2;

	// FIXME
	// ResourceHelper::getImage("interface").render(x, y, 32, 32, 128 + 32 * (SDL_GetTicks() / 4 % 2), 96, 32, 32);
}

void Battle::enemyTurn() {
	for(auto &it : m_enemies) {
		pushAction(it.second, m_actors[rand() % m_actors.size()].second, ResourceHelper::getSkill(0));
	}
}

void Battle::pushAction(Battler *actor, Battler *receiver, Item *item) {
	m_actions.push_back(new BattleAction(actor, receiver, item));
}

void Battle::processAction() {
	if(m_actions.back()->receiver()->hp() == 0) {
		if(m_actions.back()->receiver()->type() == Battler::Type::TypeEnemy) {
			m_actions.back()->setReceiver(getNextEnemyPair(1, -1).second);
		} else {
			m_actions.back()->setReceiver(getNextActorPair(1, -1).second);
		}
	}

	m_actions.back()->process();
}

void Battle::checkDead() {
	if(m_actions.back()->receiver()->hp() == 0) {
		if(m_actions.back()->animationAtEnd()) m_actions.back()->receiver()->kill();
	}
}

bool sortFunction(BattleAction *a, BattleAction *b) {
	return (a->actor()->speed() <  b->actor()->speed());
}

void Battle::sortBattleActions() {
	std::sort(m_actions.begin(), m_actions.end(), sortFunction);
}

std::pair<u8, Actor*> Battle::getNextActorPair(s8 v, s8 current) {
	do {
		current += v;
		if(current >= (s8)m_actors.size() || current < 0) {
			return std::make_pair(current, (Actor*)nullptr);
		}
	} while(getActor(current)->hp() == 0);

	return m_actors[current];
}

std::pair<u8, Enemy*> Battle::getNextEnemyPair(s8 v, s8 current) {
	do {
		current += v;
		if(current >= (s8)m_enemies.size() || current < 0) {
			return std::make_pair(current, (Enemy*)nullptr);
		} else {
		}
	} while(getEnemy(current)->hp() == 0);

	return m_enemies[current];
}

void Battle::renderBattleback() {
	// FIXME
	// m_battleback->render();
}

