/*
 * =====================================================================================
 *
 *       Filename:  BattleActionWindow.hpp
 *
 *    Description:
 *
 *        Created:  23/04/2014 18:56:41
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef BATTLEACTIONWINDOW_HPP_
#define BATTLEACTIONWINDOW_HPP_

#include "CommandWindow.hpp"

class BattleActionWindow : public CommandWindow {
	public:
		BattleActionWindow();

		void setPos(u8 pos);
};

#endif // BATTLEACTIONWINDOW_HPP_
