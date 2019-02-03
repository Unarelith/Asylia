/*
 * =====================================================================================
 *
 *       Filename:  ActorStatsWindow.hpp
 *
 *    Description:
 *
 *        Created:  13/04/2014 17:27:24
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ACTORSTATSWINDOW_HPP_
#define ACTORSTATSWINDOW_HPP_

#include "Actor.hpp"
#include "Enemy.hpp"
#include "Window.hpp"

class ActorStatsWindow : public Window {
	public:
		ActorStatsWindow();
		~ActorStatsWindow();

		void drawActors(std::vector<std::pair<u8, Actor*>> actors);
		void drawActor(Actor *actor, u8 pos);

		void drawEnemies(std::vector<std::pair<u8, Enemy*>> enemies);
		void drawEnemy(Enemy *enemy, u8 pos, u8 max);
};

#endif // ACTORSTATSWINDOW_HPP_
