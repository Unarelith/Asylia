/*
 * =====================================================================================
 *
 *       Filename:  EndState.hpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 17:46:04
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ENDSTATE_HPP_
#define ENDSTATE_HPP_

#include <gk/core/ApplicationState.hpp>

#include "CommandWindow.hpp"

class EndState : public gk::ApplicationState {
	public:
		EndState(bool disableCancel = false);

		void update() override;

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		CommandWindow m_cmdwin{192};
};

#endif // ENDSTATE_HPP_
