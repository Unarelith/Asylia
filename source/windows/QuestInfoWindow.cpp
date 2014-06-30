/*
 * =====================================================================================
 *
 *       Filename:  QuestInfoWindow.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  30/06/2014 18:52:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

QuestInfoWindow::QuestInfoWindow() : Window(200, 114, GameWindow::main->width() - 200, GameWindow::main->height() - 114) {
}

QuestInfoWindow::~QuestInfoWindow() {
}

void QuestInfoWindow::draw(Quest *quest) {
	Window::draw();
}

