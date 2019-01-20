/*
 * =====================================================================================
 *
 *       Filename:  EventAction.cpp
 *
 *    Description:
 *
 *        Created:  17/06/2014 13:18:41
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

EventAction::EventAction(u16 id, u16 actionType, ParameterList parameters) {
	m_id = id;

	m_actionType = actionType;

	m_parameters = new ParameterList(parameters);
}

EventAction::~EventAction() {
	delete m_parameters;
}

