/*
 * =====================================================================================
 *
 *       Filename:  Battle.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  23/04/2014 18:03:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef BATTLE_HPP_
#define BATTLE_HPP_

class Battle {
	public:
		Battle(const Battle &battle);
		Battle(std::string battleback, u16 exp, u16 gold);
		~Battle();
		
		void addActor(Actor *actor) { m_actors.push_back(std::make_pair(m_actorsCount, new Actor(*actor))); m_actorsCount++; }
		void addEnemy(Enemy *enemy, s16 x, s16 y) { m_enemies.push_back(std::make_pair(m_enemiesCount, new Enemy(*enemy))); m_enemiesCount++; m_enemies.back().second->setPosition(x, y); }
		
		void drawArrow(Battler *battler);
		
		void enemyTurn();
		
		void pushAction(Battler *actor, Battler *receiver, Item *item);
		void processAction();
		bool drawAction() { return m_actions.back()->drawDamages(); }
		void popAction() { m_actions.pop_back(); }
		bool actionStackEmpty() { return (m_actions.size() == 0); }
		
		void checkDead();
		
		void sortBattleActions();
		
		Actor *getActor(u8 id) { return m_actors[id].second; }
		Enemy *getEnemy(u8 id) { return m_enemies[id].second; }
		
		u8 getActorPos(u8 id) { return m_actors[id].first; }
		u8 getEnemyPos(u8 id) { return m_enemies[id].first; }
		
		std::pair<u8, Actor*> getNextActorPair(s8 v, s8 current);
		std::pair<u8, Enemy*> getNextEnemyPair(s8 v, s8 current);
		
		std::vector<std::pair<u8, Actor*>> actors() { return m_actors; }
		std::vector<std::pair<u8, Enemy*>> enemies() { return m_enemies; }
		
		void renderBattleback();
		
		u16 exp() const { return m_exp; }
		u16 gold() const { return m_gold; }
		
	private:
		std::vector<std::pair<u8, Actor*>> m_actors;
		std::vector<std::pair<u8, Enemy*>> m_enemies;
		
		u8 m_actorsCount;
		u8 m_enemiesCount;
		
		Image *m_battleback;
		
		std::vector<BattleAction*> m_actions;
		
		u16 m_exp;
		u16 m_gold;
};

#endif // BATTLE_HPP_
