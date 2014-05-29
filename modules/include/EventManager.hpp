/*
 * =====================================================================================
 *
 *       Filename:  EventManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  24/05/2014 13:22:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef EVENTMANAGER_HPP_
#define EVENTMANAGER_HPP_

class EventManager {
	public:
		static void init();
		static void free();
		
		static void loadLibs();
		
		static void initEvents();
		static void loadCharacterEvent(XMLElement *characterElement);
		static void loadChestEvent(XMLElement *chestEvent);
		
		static Event *getEventByName(std::string name) { if(!events[name]) warning("Event %s not found", name.c_str()); return events[name]; }
		
		static std::map<std::string, Event*> events;
};

#endif // EVENTMANAGER_HPP_
