/*
 * =====================================================================================
 *
 *       Filename:  EventAction.hpp
 *
 *    Description:
 *
 *        Created:  17/06/2014 13:17:13
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef EVENTACTION_HPP_
#define EVENTACTION_HPP_

#include "Parameter.hpp"

class EventAction {
	public:
		EventAction(u16 id, u16 actionType, const ParameterList &parameters)
			: m_id(id), m_actionType(actionType), m_parameters(parameters) {}

		u16 id() const { return m_id; }

		u16 actionType() const { return m_actionType; }

		ParameterList *parameters() { return &m_parameters; }

	private:
		u16 m_id;

		u16 m_actionType;

		ParameterList m_parameters;
};

#endif // EVENTACTION_HPP_
