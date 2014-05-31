/*
 * =====================================================================================
 *
 *       Filename:  VictoryWindow.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  31/05/2014 16:20:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

VictoryWindow::VictoryWindow(Battle *battle) : Window(0, 0, 200, 100) {
	m_battle = battle;
}

VictoryWindow::~VictoryWindow() {
}

void VictoryWindow::update() {
	
}

void VictoryWindow::draw() {
	printStat(10, 10, "EXP", 423, 60, 120);
}

