/*
 * =====================================================================================
 *
 *       Filename:  EventInterpreter.hpp
 *
 *    Description:
 *
 *        Created:  17/06/2014 20:40:46
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef EVENTINTERPRETER_HPP_
#define EVENTINTERPRETER_HPP_

#include "Event.hpp"
#include "EventAction.hpp"
#include "Parameter.hpp"

class EventInterpreter {
	public:
		static void free();

		static void addActionToQueue(u16 id, std::string eventName, u16 actionType, ParameterList parameters);

		static void update(Event *e);

		static std::map<std::string, std::vector<EventAction*>> actions;

		/* Actions */
		static ParameterList *getParameters(Event *e);

		static void action0(Event *e);
		static void action1(Event *e);
		static void action2(Event *e);
};

#endif // EVENTINTERPRETER_HPP_
