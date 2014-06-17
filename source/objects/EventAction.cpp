/*
 * =====================================================================================
 *
 *       Filename:  EventAction.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  17/06/2014 13:18:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

EventAction::EventAction(u16 actionID, ParameterList parameters) {
	m_actionID = actionID;
	
	m_parameters = new ParameterList(parameters);
}

EventAction::~EventAction() {
	delete m_parameters;
}

