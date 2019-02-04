/*
 * =====================================================================================
 *
 *       Filename:  SettingsState.cpp
 *
 *    Description:
 *
 *        Created:  03/05/2014 16:53:00
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/audio/AudioPlayer.hpp>

#include "ApplicationStateStack.hpp"
#include "Keyboard.hpp"
#include "SettingsState.hpp"

SettingsState::SettingsState(ApplicationState *parent) : ApplicationState(parent) {
	m_settings.addCommand("Sound");
	m_settings.addCommand("Language");

	m_sound.addCommand("ON");
	m_sound.addCommand("OFF");

	m_language.addCommand("Français");
	m_language.addCommand("English");

	m_mode = Mode::Settings;
}

void SettingsState::update() {
	if(m_mode == Mode::Settings) {
		m_settings.update();

		if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
			gk::AudioPlayer::playSound("sound-confirm");
			switch(m_settings.pos()) {
				case 0:
					m_mode = Mode::Sound;
					break;
				case 1:
					m_mode = Mode::Language;
					break;
				default: break;
			}
		}

		if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
			gk::AudioPlayer::playSound("sound-back");
			ApplicationStateStack::getInstance().pop();
		}
	}
	else if(m_mode == Mode::Sound) {
		m_sound.update();

		if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
			switch(m_sound.pos()) {
				case 0:
					gk::AudioPlayer::setMuteState(false);
					gk::AudioPlayer::playMusic("music-theme");
					gk::AudioPlayer::playSound("sound-confirm");
					break;
				case 1:
					gk::AudioPlayer::setMuteState(true);
					gk::AudioPlayer::pauseMusic();
					break;
				default: break;
			}
		}

		if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
			gk::AudioPlayer::playSound("sound-back");
			m_mode = Mode::Settings;
		}
	}
	else if(m_mode == Mode::Language) {
		m_language.update();

		if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
			gk::AudioPlayer::playSound("sound-confirm");
			switch(m_language.pos()) {
				case 0:
					LanguageManager::getInstance().init("fr-fr");
					screenshot(m_parent);
					break;
				case 1:
					LanguageManager::getInstance().init("en-us");
					screenshot(m_parent);
					break;
				default: break;
			}
		}

		if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
			gk::AudioPlayer::playSound("sound-back");
			m_mode = Mode::Settings;
			m_settings.pos(1);
		}
	}
}

void SettingsState::render() {
	renderBackground();

	if(m_mode == Mode::Settings) {
		m_settings.draw();
	}
	else if(m_mode == Mode::Sound) {
		m_settings.draw(false);

		m_sound.draw();
	}
	else if(m_mode == Mode::Language) {
		m_settings.draw(false);

		m_language.draw();
	}
}

