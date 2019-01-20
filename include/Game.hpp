/*
 * =====================================================================================
 *
 *       Filename:  Game.hpp
 *
 *    Description:
 *
 *        Created:  14/03/2014 21:27:51
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef GAME_HPP_
#define GAME_HPP_

class Game {
	public:
		Game();
		~Game();

		void mainLoop();

		static bool quit;
		static bool paused;
};

#endif // GAME_HPP_
