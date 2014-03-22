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

void Sound::init() {
	Effect::init();
}

void Sound::free() {
	Effect::free();
}

void Sound::Effect::init() {
	move = Mix_LoadWAV("audio/effects/move.wav");
	Mix_VolumeChunk(move, MIX_MAX_VOLUME);
	
	confirm = Mix_LoadWAV("audio/effects/confirm.wav");
	Mix_VolumeChunk(confirm, MIX_MAX_VOLUME);
	
	back = Mix_LoadWAV("audio/effects/back.wav");
	Mix_VolumeChunk(back, MIX_MAX_VOLUME);
	/*load("audio/effects/move.wav", move);
	load("audio/effects/confirm.wav", confirm);
	load("audio/effects/back.wav", back);*/
}

void Sound::Effect::free() {
	Mix_FreeChunk(back);
	Mix_FreeChunk(confirm);
	Mix_FreeChunk(move);
}

void Sound::Effect::load(const char *filename, Mix_Chunk *se) {
	se = Mix_LoadWAV(filename);
	if(!se) {
		error("Unable to load sound effect: %s", filename);
		exit(EXIT_FAILURE);
	}
	Mix_VolumeChunk(se, MIX_MAX_VOLUME);
}

void Sound::Effect::play(Mix_Chunk *se) {
	Mix_PlayChannel(1, se, 0);
}

