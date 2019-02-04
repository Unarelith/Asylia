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

#include <gk/core/SDLLoader.hpp>

#include "ApplicationStateStack.hpp"
#include "GameWindow.hpp"
#include "LanguageManager.hpp"

class Game {
	public:
		Game();
		~Game();

		void mainLoop();

		static bool quit;
		static bool paused;

	private:
		gk::SDLLoader m_sdlLoader;

		ApplicationStateStack m_stateStack;

		GameWindow m_window;

		LanguageManager m_languageManager;
};

#endif // GAME_HPP_
