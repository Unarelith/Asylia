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

class Player : public Character {
	public:
		Player(std::string filename, s16 x, s16 y, u8 direction);
		~Player();

		void move();

		void addTeamMember(u16 id) { m_team.push_back(BattlerManager::actors[id]); if(m_team.size() == 1) reload(m_team.back()->sprite()); }
		Actor *getTeamMember(u8 i) { return m_team[i]; }

		u16 teamSize() { return m_team.size(); }

		void addQuest(Quest *quest) { m_quests.push_back(quest); }

		std::vector<Quest*> quests() const { return m_quests; }

	private:
		std::vector<Actor*> m_team;

		std::vector<Quest*> m_quests;
};

#endif // PLAYER_HPP_
