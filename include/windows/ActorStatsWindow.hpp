/*
 * =====================================================================================
 *
 *       Filename:  ActorStatsWindow.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/04/2014 17:27:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef ACTORSTATSWINDOW_HPP_
#define ACTORSTATSWINDOW_HPP_

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
