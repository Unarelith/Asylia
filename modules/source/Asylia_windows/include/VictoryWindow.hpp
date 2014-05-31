/*
 * =====================================================================================
 *
 *       Filename:  VictoryWindow.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  31/05/2014 16:20:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef VICTORYWINDOW_HPP_
#define VICTORYWINDOW_HPP_

class VictoryWindow : public Window {
	public:
		VictoryWindow(Battle *battle);
		~VictoryWindow();
		
		void update();
		void draw();
		
	private:
		Battle *m_battle;
};

#endif // VICTORYWINDOW_HPP_
