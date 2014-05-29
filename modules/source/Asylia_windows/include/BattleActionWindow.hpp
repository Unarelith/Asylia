/*
 * =====================================================================================
 *
 *       Filename:  BattleActionWindow.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  23/04/2014 18:56:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef BATTLEACTIONWINDOW_HPP_
#define BATTLEACTIONWINDOW_HPP_

class BattleActionWindow : public CommandWindow {
	public:
		BattleActionWindow();
		~BattleActionWindow();
		
		void draw(u8 pos);
};

#endif // BATTLEACTIONWINDOW_HPP_
