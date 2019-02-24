/*
 * =====================================================================================
 *
 *       Filename:  ActorChoiceWindow.hpp
 *
 *    Description:
 *
 *        Created:  10/06/2014 15:54:15
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ACTORCHOICEWINDOW_HPP_
#define ACTORCHOICEWINDOW_HPP_

#include "SelectableWindow.hpp"

class ActorChoiceWindow : public SelectableWindow {
	public:
		ActorChoiceWindow(s16 x, s16 y, u16 width, u16 height);

		void update();

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;
};

#endif // ACTORCHOICEWINDOW_HPP_
