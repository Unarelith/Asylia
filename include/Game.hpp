/*
 * =====================================================================================
 *
 *       Filename:  Game.hpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  14/03/2014 21:27:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
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
