/*
 * =====================================================================================
 *
 *       Filename:  Event.hpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 23:50:31
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef EVENT_HPP_
#define EVENT_HPP_

#include "Character.hpp"

class Event : public Character {
	public:
		Event(const std::string &name, const std::string &appearance, u16 x, u16 y, u8 anim, bool solid = false, u16 frameWidth = 32, u16 frameHeight = 48);

		void init();

		void move(std::string function);

		void update();
		void updateActions();

		void render();

		std::string name() const { return m_name; }

		void lock() { m_locked = true; }
		void unlock() { m_locked = false; }
		bool isLocked() const { return m_locked; }

		s16 currentActionID() const { return m_currentActionID; }
		void currentActionID(s16 actionID) { m_currentActionID = actionID; }

	private:
		s16 m_currentActionID;

		std::string m_folder;
		std::string m_name;

		bool m_locked;
};

#endif // EVENT_HPP_
