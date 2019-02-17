/*
 * =====================================================================================
 *
 *       Filename:  MenuState.hpp
 *
 *    Description:
 *
 *        Created:  21/03/2014 18:21:02
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MENUSTATE_HPP_
#define MENUSTATE_HPP_

#include <memory>

#include <gk/core/ApplicationState.hpp>

#include "ActorChoiceWindow.hpp"
#include "CommandWindow.hpp"

class MenuState : public gk::ApplicationState {
	public:
		MenuState(gk::ApplicationState *parent = nullptr);

		void loadCommandWindow();

		void update();
		void render();

		CommandWindow *cmdwin() { return m_cmdwin.get(); }

		void actorChoiceModeOn() { m_actorChoiceMode = true; }

	private:
		std::unique_ptr<CommandWindow> m_cmdwin;
		std::unique_ptr<ActorChoiceWindow> m_actorChoicewin;

		bool m_actorChoiceMode;
};

#endif // MENUSTATE_HPP_
