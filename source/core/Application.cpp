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
#include "Config.hpp"
#include "GameWindow.hpp"
#include "Interface.hpp"
#include "Keyboard.hpp"
#include "MapState.hpp"
#include "TimeManager.hpp"

#include "ActorLoader.hpp"
#include "AnimationLoader.hpp"
#include "ArmorLoader.hpp"
#include "AudioLoader.hpp"
#include "EnemyLoader.hpp"
#include "EventLoader.hpp"
#include "ItemLoader.hpp"
#include "PlayerLoader.hpp"
#include "QuestLoader.hpp"
#include "SkillLoader.hpp"
#include "SpriteAnimationLoader.hpp"
#include "TilesetLoader.hpp"
#include "TroopLoader.hpp"
#include "WeaponLoader.hpp"

Application::Application(int argc, char **argv) : gk::CoreApplication(argc, argv) {
}

void Application::init() {
	gk::CoreApplication::init();

	m_window.open(APP_NAME);
	GameWindow::main = &m_window;

	LanguageManager::setInstance(m_languageManager);

	LuaHandler::setInstance(m_luaHandler);
	m_luaHandler.init();

	m_resourceHandler.loadConfigFile<AudioLoader>("resources/config/audio.xml");
	m_resourceHandler.loadConfigFile<SpriteAnimationLoader>("resources/config/spriteAnimations.xml");
	m_resourceHandler.loadConfigFile<AnimationLoader>("resources/config/animations.xml");
	m_resourceHandler.loadConfigFile<ItemLoader>("resources/config/items.xml");
	m_resourceHandler.loadConfigFile<ArmorLoader>("resources/config/armors.xml");
	m_resourceHandler.loadConfigFile<WeaponLoader>("resources/config/weapons.xml");
	m_resourceHandler.loadConfigFile<SkillLoader>("resources/config/skills.xml");
	m_resourceHandler.loadConfigFile<ActorLoader>("resources/config/actors.xml");
	m_resourceHandler.loadConfigFile<EnemyLoader>("resources/config/enemies.xml");
	m_resourceHandler.loadConfigFile<TroopLoader>("resources/config/troops.xml");
	m_resourceHandler.loadConfigFile<QuestLoader>("resources/config/quests.xml");
	m_resourceHandler.loadConfigFile<PlayerLoader>("resources/config/player.xml");
	m_resourceHandler.loadConfigFile<EventLoader>("resources/config/events.xml");
	m_resourceHandler.loadConfigFile<TilesetLoader>("resources/config/tilesets.xml");

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

