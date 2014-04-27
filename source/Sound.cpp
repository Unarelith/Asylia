/*
 * =====================================================================================
 *
 *       Filename:  Sound.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 13:42:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Mix_Chunk *Sound::Effect::move = NULL;
Mix_Chunk *Sound::Effect::confirm = NULL;
Mix_Chunk *Sound::Effect::back = NULL;
Mix_Chunk *Sound::Effect::blocked = NULL;

Mix_Music *Sound::Music::battle = NULL;
Mix_Music *Sound::Music::theme = NULL;
Mix_Music *Sound::Music::title = NULL;

void Sound::init() {
	Effect::init();
	Music::init();
}

void Sound::free() {
	Music::free();
	Effect::free();
}

void Sound::Effect::init() {
	load("audio/effects/move.wav", &move);
	load("audio/effects/confirm.wav", &confirm);
	load("audio/effects/back.wav", &back);
	load("audio/effects/blocked.wav", &blocked);
}

void Sound::Effect::free() {
	Mix_FreeChunk(blocked);
	Mix_FreeChunk(back);
	Mix_FreeChunk(confirm);
	Mix_FreeChunk(move);
}

void Sound::Effect::load(const char *filename, Mix_Chunk **se) {
	*se = Mix_LoadWAV(filename);
	if(!*se) {
		error("Unable to load sound effect: %s", filename);
		exit(EXIT_FAILURE);
	}
	Mix_VolumeChunk(*se, MIX_MAX_VOLUME);
}

void Sound::Effect::play(Mix_Chunk *se) {
#ifndef SOUND_MUTE
	Mix_PlayChannel(1, se, 0);
#endif
}

void Sound::Music::init() {
	load("audio/music/battle.mid", &battle);
	load("audio/music/theme.mid", &theme);
	load("audio/music/title.mid", &title);
}

void Sound::Music::free() {
	Mix_FreeMusic(title);
	Mix_FreeMusic(theme);
	Mix_FreeMusic(battle);
}

void Sound::Music::load(const char *filename, Mix_Music **music) {
	*music = Mix_LoadMUS(filename);
	if(!*music) {
		error("Unable to load sound effect: %s", filename);
		exit(EXIT_FAILURE);
	}
}

void Sound::Music::play(Mix_Music *music, int loops) {
#ifndef SOUND_MUTE
	Mix_VolumeMusic(MIX_MAX_VOLUME);
	Mix_PlayMusic(music, loops);
#endif
}

void Sound::Music::halt() {
	Mix_HaltMusic();
}

