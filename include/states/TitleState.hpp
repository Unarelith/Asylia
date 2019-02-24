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
#include <gk/graphics/Image.hpp>

#include "CommandWindow.hpp"

class TitleState : public gk::ApplicationState {
	public:
		TitleState();

		void update() override;

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		gk::Image m_background{"texture-interface-titlescreen"};
		CommandWindow m_cmdwin{192};
};

#endif // TITLESTATE_HPP_
