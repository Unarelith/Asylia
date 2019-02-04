/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:
 *
 *        Created:  14/03/2014 21:22:59
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Game.hpp"

int main(int, char *[]) {
	try {
		Game game;
		game.mainLoop();
	}
	catch (const gk::Exception &e) {
		std::cerr << "Fatal error " << e.what() << std::endl;
		return 1;
	}

	return 0;
}

