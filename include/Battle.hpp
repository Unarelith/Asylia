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
	public:;
		Battle(std::string battleback);
		~Battle();
		
		void addActor(Actor *actor) { m_actors.push_back(std::make_pair(m_actorsCount, new Actor(*actor))); m_actorsCount++; }
		void addEnemy(Enemy *enemy, s16 x, s16 y) { m_enemies.push_back(std::make_pair(m_enemiesCount, new Enemy(*enemy))); m_enemiesCount++; m_enemies.back().second->setPosition(GameWindow::main->viewportX() + x, GameWindow::main->viewportY() + y); }
		
		void drawArrow(Battler *battler);
		
		void enemyTurn();
		
		void pushAction(Battler *actor, Battler *receiver, Item *item);
		void processAction();
		bool drawAction() { return m_actionStack.top()->drawDamages(); }
		void popAction() { m_actionStack.pop(); }
		bool actionStackEmpty() { return (m_actionStack.size() == 0); }
		
		void checkDead();
		
		Actor *getActor(u8 id) { return m_actors[id].second; }
		Enemy *getEnemy(u8 id) { return m_enemies[id].second; }
		
		u8 getActorPos(u8 id) { return m_actors[id].first; }
		u8 getEnemyPos(u8 id) { return m_enemies[id].first; }
		
		std::pair<u8, Actor*> getNextActorPair(s8 v, s8 current);
		std::pair<u8, Enemy*> getNextEnemyPair(s8 v, s8 current);
		
		std::vector<std::pair<u8, Actor*>> actors() { return m_actors; }
		std::vector<std::pair<u8, Enemy*>> enemies() { return m_enemies; }
		
		void renderBattleback() { m_battleback->render(); }
		
	private:
		std::vector<std::pair<u8, Actor*>> m_actors;
		std::vector<std::pair<u8, Enemy*>> m_enemies;
		
		u8 m_actorsCount;
		u8 m_enemiesCount;
		
		Image *m_battleback;
		
		std::stack<BattleAction*> m_actionStack;
};

#endif // BATTLE_HPP_
