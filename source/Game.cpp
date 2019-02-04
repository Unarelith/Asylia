/*
 * =====================================================================================
 *
 *       Filename:  Game.cpp
 *
 *    Description:
 *
 *        Created:  14/03/2014 21:26:04
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <cstdlib>
#include <ctime>

#include "Config.hpp"
#include "Game.hpp"
#include "GameWindow.hpp"
#include "Interface.hpp"
#include "Keyboard.hpp"
#include "MapState.hpp"
#include "Sound.hpp"
#include "TimeManager.hpp"

bool Game::quit = false;
bool Game::paused = false;

Game::Game() {
	std::srand(std::time(nullptr));

	m_sdlLoader.load();

	m_window.open(APP_NAME);
	GameWindow::main = &m_window;

	ApplicationStateStack::setInstance(m_stateStack);
	LanguageManager::setInstance(m_languageManager);
	gk::ResourceHandler::setInstance(m_resourceHandler);

	Sound::init();

	Interface::init();

	m_languageManager.init("en-us");

	m_stateStack.push<MapState>().init();
}

Game::~Game() {
	Sound::free();
}

void Game::mainLoop() {
	while(!quit) {
		if(TimeManager::isTimeToUpdate()) {
			m_stateStack.top().pollEvents();

			Keyboard::update();

			if(Game::paused == true) continue;

			m_stateStack.top().update();

			if(TimeManager::hasEnoughTimeToDraw()) {
				TimeManager::beginMeasuringRenderingTime();

				GameWindow::main->clear();

				m_stateStack.top().render();

				TimeManager::renderRTMCounter(); // Rendering time mean

				Interface::renderHUD();

				GameWindow::main->update();

				TimeManager::endMeasuringRenderingTime();
			}
		} else {
			TimeManager::waitUntilItsTime();
		}

		TimeManager::measureFrameDuration();
	}
}

