/*
 * =====================================================================================
 *
 *       Filename:  ApplicationState.hpp
 *
 *    Description:
 *
 *        Created:  20/03/2014 21:01:10
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef APPLICATIONSTATE_HPP_
#define APPLICATIONSTATE_HPP_

#include <gk/core/ApplicationState.hpp>

class ApplicationState : public gk::ApplicationState {
	public:
		ApplicationState(ApplicationState *parent = nullptr);
		virtual ~ApplicationState() = default;

		virtual void update() = 0;
		virtual void render() = 0;

		typedef enum {
			None,
			Map,
		} Type;

		Type type() const { return m_type; }

		ApplicationState *parent() const { return m_parent; }

	protected:
		Type m_type;

		ApplicationState *m_parent;
};

#endif // APPLICATIONSTATE_HPP_
