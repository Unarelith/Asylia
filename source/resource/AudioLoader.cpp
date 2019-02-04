/*
 * =====================================================================================
 *
 *       Filename:  AudioLoader.cpp
 *
 *    Description:
 *
 *        Created:  24/01/2018 21:33:39
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/audio/Music.hpp>
#include <gk/audio/Sound.hpp>
#include <gk/core/XMLFile.hpp>
#include <gk/resource/ResourceHandler.hpp>

#include "AudioLoader.hpp"

void AudioLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	tinyxml2::XMLElement *rootElement = doc.FirstChildElement("audio").ToElement();
	tinyxml2::XMLElement *musicElement = rootElement->FirstChildElement("music");
	while(musicElement) {
		std::string name = musicElement->Attribute("name");
		int volume = musicElement->IntAttribute("volume");

		gk::Music &music = handler.add<gk::Music>("music-" + name);
		music.openFromFile("resources/audio/music/" + name + ".mp3");
		music.setVolume(volume);

		musicElement = musicElement->NextSiblingElement("music");
	}

	tinyxml2::XMLElement *soundElement = rootElement->FirstChildElement("sound");
	while(soundElement) {
		std::string name = soundElement->Attribute("name");
		int volume = soundElement->IntAttribute("volume");

		gk::Sound &sound = handler.add<gk::Sound>("sound-" + name);
		sound.openFromFile("resources/audio/sound/" + name + ".wav");
		sound.setVolume(volume);

		soundElement = soundElement->NextSiblingElement("sound");
	}
}

