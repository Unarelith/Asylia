/*
 * =====================================================================================
 *
 *       Filename:  Player.hpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 19:48:20
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Actor.hpp"
#include "Character.hpp"
#include "Quest.hpp"

class Player : public Character {
	public:
		Player(const std::string &filename, s16 x, s16 y, u8 direction);

		void move();

		void addTeamMember(u16 id);
		Actor *getTeamMember(u8 i) { return m_team[i]; }

		u16 teamSize() { return m_team.size(); }

		void addQuest(Quest *quest) { m_quests.push_back(quest); }

		std::vector<Quest*> quests() const { return m_quests; }

	private:
		std::vector<Actor*> m_team;

		std::vector<Quest*> m_quests;
};

#endif // PLAYER_HPP_
