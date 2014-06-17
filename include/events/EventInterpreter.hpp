/*
 * =====================================================================================
 *
 *       Filename:  EventInterpreter.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  17/06/2014 20:40:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef EVENTINTERPRETER_HPP_
#define EVENTINTERPRETER_HPP_

class EventInterpreter {
	public:
		static void free();
		
		static void addActionToQueue(std::string eventName, u16 actionID, ParameterList parameters);
		
		static void update(Event *e);
		
		static std::map<std::string, std::queue<EventAction*>> actions;
		
		/* Actions */
		static void action0(Event *e);
		static void action1(Event *e);
};

#endif // EVENTINTERPRETER_HPP_
