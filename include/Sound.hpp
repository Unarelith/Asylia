/*
 * =====================================================================================
 *
 *       Filename:  Sound.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 13:41:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef SOUND_HPP_
#define SOUND_HPP_

namespace Sound {
	void init();
	void free();
	
	namespace Effect {
		void init();
		void free();
		
		void load(const char *filename, Mix_Chunk *se);
		void play(Mix_Chunk *se);
		
		extern Mix_Chunk *move;
		extern Mix_Chunk *confirm;
		extern Mix_Chunk *back;
	};
};

#endif // SOUND_HPP_
