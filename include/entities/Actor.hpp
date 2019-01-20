/*
 * =====================================================================================
 *
 *       Filename:  Actor.hpp
 *
 *    Description:
 *
 *        Created:  22/04/2014 19:30:35
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ACTOR_HPP_
#define ACTOR_HPP_

class Actor : public Battler {
	public:
		Actor(std::string name, std::string appearance, u8 level);
		~Actor();

		u16 totalAtk();
		u16 totalDef();

		Equipment *equipment() { return &m_equipment; }

	private:
		Equipment m_equipment;
};

#endif // ACTOR_HPP_
