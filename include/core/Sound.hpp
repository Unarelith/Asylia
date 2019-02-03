/*
 * =====================================================================================
 *
 *       Filename:  Sound.hpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 13:41:57
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SOUND_HPP_
#define SOUND_HPP_

#include "SDLHeaders.hpp"

namespace Sound {
	void init();
	void free();

	namespace Effect {
		void init();
		void free();

		void load(const char *filename, Mix_Chunk **se);
		void play(Mix_Chunk *se);

		extern bool mute;

		extern Mix_Chunk *move;
		extern Mix_Chunk *confirm;
		extern Mix_Chunk *back;
		extern Mix_Chunk *blocked;
	};

	namespace Music {
		void init();
		void free();

		void load(const char *filename, Mix_Music **music);
		void play(Mix_Music *music, int loops);

		void halt();

		void mute();
		void unmute();

		extern Mix_Music *battle;
		extern Mix_Music *theme;
		extern Mix_Music *title;

		extern Mix_Music *current;
	};
};

#endif // SOUND_HPP_
