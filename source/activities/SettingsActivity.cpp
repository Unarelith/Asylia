/*
 * =====================================================================================
 *
 *       Filename:  SettingsActivity.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/05/2014 16:53:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

SettingsActivity::SettingsActivity(Activity *parent) : Activity(parent) {
	m_settings = new CommandWindow(150, 160, 150, 96);
	
	m_settings->addCommand("Sound");
	m_settings->addCommand("Language");
	
	m_sound = new CommandWindow(300, 160, 150, 96);
	
	m_sound->addCommand("ON");
	m_sound->addCommand("OFF");
	
	m_language = new CommandWindow(300, 160, 150, 96);
	
	m_language->addCommand("Français");
	m_language->addCommand("English");
	
	m_mode = Mode::Settings;
}

SettingsActivity::~SettingsActivity() {
	delete m_language;
	delete m_sound;
	delete m_settings;
}

void SettingsActivity::update() {
	if(m_mode == Mode::Settings) {
		m_settings->update();
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
			Sound::Effect::play(Sound::Effect::confirm);
			switch(m_settings->pos()) {
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
			Sound::Effect::play(Sound::Effect::back);
			ActivityManager::pop();
		}
	}
	else if(m_mode == Mode::Sound) {
		m_sound->update();
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
			switch(m_sound->pos()) {
				case 0:
					Sound::Effect::mute = false;
					Sound::Music::unmute();
					Sound::Effect::play(Sound::Effect::confirm);
					break;
				case 1:
					Sound::Effect::mute = true;
					Sound::Music::mute();
					break;
				default: break;
			}
		}
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
			Sound::Effect::play(Sound::Effect::back);
			m_mode = Mode::Settings;
		}
	}
	else if(m_mode == Mode::Language) {
		m_language->update();
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
			Sound::Effect::play(Sound::Effect::confirm);
			switch(m_language->pos()) {
				case 0:
					LanguageManager::init("fr-fr");
					screenshot(m_parent);
					break;
				case 1:
					LanguageManager::init("en-us");
					screenshot(m_parent);
					break;
				default: break;
			}
		}
		
		if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
			Sound::Effect::play(Sound::Effect::back);
			m_mode = Mode::Settings;
			m_settings->pos(1);
		}
	}
}

void SettingsActivity::render() {
	SDL_RenderCopy(GameWindow::main->renderer(), m_background, NULL, NULL);
	
	if(m_mode == Mode::Settings) {
		m_settings->draw();
	}
	else if(m_mode == Mode::Sound) {
		m_settings->draw(false);
		
		m_sound->draw();
	}
	else if(m_mode == Mode::Language) {
		m_settings->draw(false);
		
		m_language->draw();
	}
}

