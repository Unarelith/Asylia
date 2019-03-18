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

#include "Battle.hpp"
#include "Window.hpp"

class ActorStatsWindow : public Window {
	public:
		ActorStatsWindow();

		void setBattle(Battle *battle) { m_battle = battle; }

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;
		void drawActor(Actor *actor, u8 pos, gk::RenderTarget &target, gk::RenderStates states) const;
		void drawEnemy(Enemy *enemy, gk::RenderTarget &target, gk::RenderStates states) const;

		Battle *m_battle = nullptr;
};

#endif // ACTORSTATSWINDOW_HPP_
