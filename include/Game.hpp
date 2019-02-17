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

#include <gk/core/CoreApplication.hpp>

#include "ApplicationStateStack.hpp"
#include "GameWindow.hpp"
#include "LanguageManager.hpp"

class Game : public gk::CoreApplication {
	public:
		Game(int argc, char **argv);

		void init() override;

		static bool paused;

	private:
		void onEvent(const SDL_Event &event) override;
		void mainLoop() override;

		ApplicationStateStack m_stateStack;

		GameWindow m_window;

		LanguageManager m_languageManager;
};

#endif // GAME_HPP_
