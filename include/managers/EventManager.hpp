/*
 * =====================================================================================
 *
 *       Filename:  EventManager.hpp
 *
 *    Description:
 *
 *        Created:  24/05/2014 13:22:26
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef EVENTMANAGER_HPP_
#define EVENTMANAGER_HPP_

#include <memory>

#include <gk/core/XMLFile.hpp>

#include "Debug.hpp"
#include "Event.hpp"

class EventManager : public Singleton<EventManager> {
	public:
		void init();

		void loadLibs();

		void initEvents();
		void loadCharacterEvent(tinyxml2::XMLElement *characterElement);
		void loadChestEvent(tinyxml2::XMLElement *chestEvent);

		Event *getEventByName(const std::string &name) { if(!m_events[name]) warning("Event %s not found", name.c_str()); return m_events[name].get(); }

	private:
		std::map<std::string, std::unique_ptr<Event>> m_events;
};

#endif // EVENTMANAGER_HPP_
