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
#include <gk/core/input/GamePad.hpp>
#include <gk/graphics/Font.hpp>
#include <gk/graphics/Image.hpp>
#include <gk/resource/TextureLoader.hpp>

#include "Application.hpp"
#include "Config.hpp"
#include "TimeManager.hpp"
#include "TitleState.hpp"

#include "ActorLoader.hpp"
#include "ArmorLoader.hpp"
#include "AudioLoader.hpp"
#include "EnemyLoader.hpp"
#include "EventLoader.hpp"
#include "ItemLoader.hpp"
#include "MapLoader.hpp"
#include "PlayerLoader.hpp"
#include "QuestLoader.hpp"
#include "SkillLoader.hpp"
#include "SpriteAnimationLoader.hpp"
#include "TilesetLoader.hpp"
#include "TilemapLoader.hpp"
#include "TroopLoader.hpp"
#include "WeaponLoader.hpp"

Application::Application(int argc, char **argv) : gk::CoreApplication(argc, argv) {
}

void Application::init() {
	gk::CoreApplication::init();

	gk::GamePad::init(m_keyboardHandler);

	createWindow(SCREEN_WIDTH, SCREEN_HEIGHT, APP_NAME);

	m_shader.loadFromFile("resources/shaders/game.v.glsl", "resources/shaders/game.f.glsl");
	m_renderStates.shader = &m_shader;

	LanguageManager::setInstance(m_languageManager);
	m_languageManager.init("en-us");

	LuaHandler::setInstance(m_luaHandler);
	m_luaHandler.init();

	m_resourceHandler.add<gk::Font>("font-default", "resources/fonts/arial.ttf");

	m_resourceHandler.loadConfigFile<gk::TextureLoader>("resources/config/textures.xml");
	m_resourceHandler.add<gk::Image>("image-interface", "texture-interface-window");

	m_resourceHandler.loadConfigFile<AudioLoader>("resources/config/audio.xml");
	m_resourceHandler.loadConfigFile<SpriteAnimationLoader>("resources/config/spriteAnimations.xml");
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
	m_resourceHandler.loadConfigFile<MapLoader>("resources/config/maps.xml");
	m_resourceHandler.loadConfigFile<TilemapLoader>("resources/config/tilemaps.xml");

	m_stateStack.push<TitleState>();
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

			if (!m_stateStack.empty())
				m_stateStack.top().update();

			m_clock.updateGame([](){});

			if(TimeManager::hasEnoughTimeToDraw()) {
				TimeManager::beginMeasuringRenderingTime();

				m_clock.drawGame([](){});

				m_window.clear();

				if(!m_stateStack.empty())
					m_window.draw(m_stateStack.top(), m_renderStates);

				m_window.display();

				TimeManager::endMeasuringRenderingTime();
			}
		} else {
			TimeManager::waitUntilItsTime();
		}

		TimeManager::measureFrameDuration();
	}
}

