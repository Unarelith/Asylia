/*
 * =====================================================================================
 *
 *       Filename:  Interface.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 00:35:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Image *Interface::pad = NULL;
Image *Interface::buttonA = NULL;
Image *Interface::buttonB = NULL;
Image *Interface::buttonMenu = NULL;

Font *Interface::defaultFont = NULL;
Image *Interface::interface = NULL;

void Interface::init() {
	defaultFont = new Font("fonts/arial.ttf");
	
	interface = new Image("graphics/interface/Interface.png");
	
	pad = new Image("graphics/interface/DPad.png");
	pad->setAlpha(150);
	
	buttonA = new Image("graphics/interface/ButtonA.png");
	buttonA->setAlpha(150);
	
	buttonB = new Image("graphics/interface/ButtonA.png");
	buttonB->setAlpha(150);
	
	buttonMenu = new Image("graphics/interface/ButtonA.png");
	buttonMenu->setAlpha(150);
}

void Interface::free() {
	delete interface;
	
	delete defaultFont;
	
	delete pad;
	delete buttonA;
	delete buttonB;
	delete buttonMenu;
}

void Interface::renderPad() {
	pad->render(GameWindow::main->viewportX() + 16, GameWindow::main->viewportY() + GameWindow::main->height() - pad->height() - 16, pad->width(), pad->height());
	
	buttonA->render(GameWindow::main->viewportX() + GameWindow::main->width() - buttonA->width() - 16, GameWindow::main->viewportY() + GameWindow::main->height() - buttonA->height() - 16, buttonA->width(), buttonA->height());
	buttonB->render(GameWindow::main->viewportX() + GameWindow::main->width() - buttonB->width() - 16, GameWindow::main->viewportY() + GameWindow::main->height() - buttonB->height() - 64, buttonB->width(), buttonB->height());
	buttonMenu->render(GameWindow::main->viewportX() + GameWindow::main->width() - buttonMenu->width() - 16, GameWindow::main->viewportY() + 16, buttonMenu->width(), buttonMenu->height());
}

void Interface::renderHUD() {
#ifdef PAD
	renderPad();
#endif
}

