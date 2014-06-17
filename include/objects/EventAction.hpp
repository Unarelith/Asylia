/*
 * =====================================================================================
 *
 *       Filename:  EventAction.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  17/06/2014 13:17:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef EVENTACTION_HPP_
#define EVENTACTION_HPP_

class EventAction {
	public:
		EventAction(u16 id, u16 actionType, ParameterList parameters);
		~EventAction();
		
		u16 id() const { return m_id; }
		
		u16 actionType() const { return m_actionType; }
		
		ParameterList *parameters() const { return m_parameters; }
		
	private:
		u16 m_id;
		
		u16 m_actionType;
		
		ParameterList *m_parameters;
};

#endif // EVENTACTION_HPP_
