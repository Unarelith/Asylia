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
