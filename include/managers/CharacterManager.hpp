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

#include <memory>

#include "Player.hpp"

class CharacterManager : public Singleton<CharacterManager> {
	public:
		void init();

		void loadActorsTeam();

		Player *getPlayer() { return m_player.get(); }

	private:
		std::unique_ptr<Player> m_player;
};

#endif // CHARACTERMANAGER_HPP_
