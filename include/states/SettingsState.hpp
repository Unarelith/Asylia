/*
 * =====================================================================================
 *
 *       Filename:  SettingsState.hpp
 *
 *    Description:
 *
 *        Created:  03/05/2014 16:51:32
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SETTINGSSTATE_HPP_
#define SETTINGSSTATE_HPP_

#include <gk/core/ApplicationState.hpp>

#include "CommandWindow.hpp"

class SettingsState : public gk::ApplicationState {
	public:
		SettingsState(gk::ApplicationState *parent = nullptr);

		void update() override;

		enum Mode {
			Settings,
			Language,
			Sound
		};

		void mode(Mode mode) { m_mode = mode; }

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		CommandWindow m_settings{150, 160, 150};
		CommandWindow m_sound{300, 160, 150};
		CommandWindow m_language{300, 160, 150};

		Mode m_mode;
};

#endif // SETTINGSSTATE_HPP_
