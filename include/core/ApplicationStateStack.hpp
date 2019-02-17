/*
 * =====================================================================================
 *
 *       Filename:  ApplicationStateStack.hpp
 *
 *    Description:
 *
 *        Created:  20/03/2014 21:15:19
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef APPLICATIONSTATESTACK_HPP_
#define APPLICATIONSTATESTACK_HPP_

#include <stack>

#include <gk/core/ApplicationStateStack.hpp>

#include "ApplicationState.hpp"

class ApplicationStateStack : public gk::ApplicationStateStack {
	public:
		ApplicationState &top() { return (ApplicationState&)gk::ApplicationStateStack::top(); }

		static ApplicationStateStack &getInstance() { return (ApplicationStateStack&)gk::ApplicationStateStack::getInstance(); }
};

#endif // APPLICATIONSTATESTACK_HPP_
