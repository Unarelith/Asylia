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

SettingsActivity::SettingsActivity() {
	m_settings = new CommandWindow(150, 160, 150, 96);
	
	m_settings->addCommand(_t("Sound"));
	m_settings->addCommand(_t("Language"));
	
	m_sound = new CommandWindow(300, 160, 150, 96);
	
	m_sound->addCommand(_t("ON"));
	m_sound->addCommand(_t("OFF"));
	
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
			Sound::Effect::play(Sound::Effect::confirm);
			switch(m_sound->pos()) {
				case 0:
					Sound::mute = false;
					break;
				case 1:
					Sound::mute = true;
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
					ActivityManager::pop();
					ActivityManager::pop();
					ActivityManager::push(new MenuActivity);
					((MenuActivity*)ActivityManager::top())->cmdwin()->pos(5);
					ActivityManager::push(new SettingsActivity);
					((SettingsActivity*)ActivityManager::top())->mode(Mode::Language);
					break;
				case 1:
					LanguageManager::init("en-us");
					ActivityManager::pop();
					ActivityManager::pop();
					ActivityManager::push(new MenuActivity);
					((MenuActivity*)ActivityManager::top())->cmdwin()->pos(5);
					ActivityManager::push(new SettingsActivity);
					((SettingsActivity*)ActivityManager::top())->mode(Mode::Language);
					m_language->pos(1);
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
	MenuActivity::render();
	
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

