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
#include "AudioLoader.hpp"
#include "Config.hpp"
#include "Game.hpp"
#include "GameWindow.hpp"
#include "Interface.hpp"
#include "Keyboard.hpp"
#include "MapState.hpp"
#include "TimeManager.hpp"

bool Game::paused = false;

Game::Game(int argc, char **argv) : gk::CoreApplication(argc, argv) {
}

void Game::init() {
	gk::CoreApplication::init();

	m_window.open(APP_NAME);
	GameWindow::main = &m_window;

	ApplicationStateStack::setInstance(m_stateStack);
	LanguageManager::setInstance(m_languageManager);

	m_resourceHandler.loadConfigFile<AudioLoader>("resources/config/audio.xml");

	Interface::init();

	m_languageManager.init("en-us");

	m_stateStack.push<MapState>();
}

void Game::mainLoop() {
	while(m_stateStack.size()) {
		if(TimeManager::isTimeToUpdate()) {
			if (!m_stateStack.empty())
				m_stateStack.top().pollEvents();

			Keyboard::update();

			if(Game::paused == true) continue;

			if (!m_stateStack.empty())
				m_stateStack.top().update();

			if(TimeManager::hasEnoughTimeToDraw()) {
				TimeManager::beginMeasuringRenderingTime();

				m_window.clear();

				if(!m_stateStack.empty()) {
					m_stateStack.top().render();
				}

				TimeManager::renderRTMCounter(); // Rendering time mean

				Interface::renderHUD();

				m_window.update();

				TimeManager::endMeasuringRenderingTime();
			}
		} else {
			TimeManager::waitUntilItsTime();
		}

		TimeManager::measureFrameDuration();
	}

	// while(m_stateStack.size()) {
	// 	m_stateStack.top().pollEvents();
    //
	// 	Keyboard::update();
    //
	// 	if(Game::paused == true) continue;
    //
	// 	m_clock.updateGame([&] {
	// 		if (!m_stateStack.empty())
	// 			m_stateStack.top().update();
	// 	});
    //
	// 	m_clock.drawGame([&] {
	// 		m_window.clear();
    //
	// 		if(!m_stateStack.empty()) {
	// 			m_stateStack.top().render();
	// 		}
    //
	// 		TimeManager::renderRTMCounter(); // Rendering time mean
    //
	// 		Interface::renderHUD();
    //
	// 		m_window.update();
	// 	});
	// }
}

