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
	pad->setAlphaMod(150);
	
	buttonA = new Image("graphics/interface/ButtonA.png");
	buttonA->setAlphaMod(150);
	
	buttonB = new Image("graphics/interface/ButtonA.png");
	buttonB->setAlphaMod(150);
	
	buttonMenu = new Image("graphics/interface/ButtonA.png");
	buttonMenu->setAlphaMod(150);
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
	pad->render(16, GameWindow::main->height() - pad->height() * 1.5 - 16, pad->width() * 1.5, pad->height() * 1.5);
	
	buttonA->render(GameWindow::main->width() - buttonA->width() * 1.5 - 16, GameWindow::main->height() - buttonA->height() * 1.5 - 16, buttonA->width() * 1.5, buttonA->height() * 1.5);
	buttonB->render(GameWindow::main->width() - buttonB->width() * 1.5 - 16, GameWindow::main->height() - buttonB->height() * 1.5 - 64, buttonB->width() * 1.5, buttonB->height() * 1.5);
	buttonMenu->render(GameWindow::main->width() - buttonMenu->width() * 1.5 - 16, 16, buttonMenu->width() * 1.5, buttonMenu->height() * 1.5);
}

void Interface::renderHUD() {
#ifdef PAD
	renderPad();
#endif
}

