/*
 * =====================================================================================
 *
 *       Filename:  Application.cpp
 *
 *    Description:
 *
 *        Created:  14/03/2014 21:26:04
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "AudioLoader.hpp"
#include "Config.hpp"
#include "GameWindow.hpp"
#include "Interface.hpp"
#include "Keyboard.hpp"
#include "MapState.hpp"
#include "TimeManager.hpp"

Application::Application(int argc, char **argv) : gk::CoreApplication(argc, argv) {
}

void Application::init() {
	gk::CoreApplication::init();

	m_window.open(APP_NAME);
	GameWindow::main = &m_window;

	LanguageManager::setInstance(m_languageManager);

	m_resourceHandler.loadConfigFile<AudioLoader>("resources/config/audio.xml");

	Interface::init();

	m_languageManager.init("en-us");

	m_stateStack.push<MapState>();
}

void Application::onEvent(const SDL_Event &event) {
	if (event.type == SDL_QUIT) {
		m_stateStack.clear();
	}
}

void Application::mainLoop() {
	while(m_stateStack.size()) {
		if(TimeManager::isTimeToUpdate()) {
			handleEvents();

			Keyboard::update();

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

