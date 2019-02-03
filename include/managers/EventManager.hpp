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

#include "Debug.hpp"
#include "Event.hpp"
#include "XMLFile.hpp"

class EventManager {
	public:
		static void init();
		static void free();

		static void loadLibs();

		static void initEvents();
		static void loadCharacterEvent(tinyxml2::XMLElement *characterElement);
		static void loadChestEvent(tinyxml2::XMLElement *chestEvent);

		static Event *getEventByName(std::string name) { if(!events[name]) warning("Event %s not found", name.c_str()); return events[name]; }

		static std::map<std::string, Event*> events;
};

#endif // EVENTMANAGER_HPP_
