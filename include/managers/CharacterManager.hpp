/*
 * =====================================================================================
 *
 *       Filename:  CharacterManager.hpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 20:21:11
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef CHARACTERMANAGER_HPP_
#define CHARACTERMANAGER_HPP_

#include "Player.hpp"

class CharacterManager {
	public:
		static void init();
		static void free();

		static void loadActorsTeam();

		static Player *getPlayer() { return player; }

		static Player *player;
};

#endif // CHARACTERMANAGER_HPP_
