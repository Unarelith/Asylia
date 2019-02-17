/*
 * =====================================================================================
 *
 *       Filename:  TitleState.hpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 17:18:32
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TITLESTATE_HPP_
#define TITLESTATE_HPP_

#include <gk/core/ApplicationState.hpp>

#include "CommandWindow.hpp"
#include "Image.hpp"

class TitleState : public gk::ApplicationState {
	public:
		TitleState();

		void update();
		void render();

	private:
		Image m_background{"graphics/interface/TitleScreen.jpg"};
		CommandWindow m_cmdwin{192};
};

#endif // TITLESTATE_HPP_
