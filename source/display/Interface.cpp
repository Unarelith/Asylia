/*
 * =====================================================================================
 *
 *       Filename:  Interface.cpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 00:35:50
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/resource/ResourceHandler.hpp>

#include "GameWindow.hpp"
#include "Interface.hpp"

Image *Interface::pad = nullptr;
Image *Interface::buttonA = nullptr;
Image *Interface::buttonB = nullptr;
Image *Interface::buttonMenu = nullptr;

Font *Interface::defaultFont = nullptr;
Image *Interface::interface = nullptr;

void Interface::init() {
	auto &r = gk::ResourceHandler::getInstance();

	defaultFont = &r.add<Font>("font-default", "resources/fonts/arial.ttf");

	interface = &r.add<Image>("image-interface", "resources/graphics/interface/Interface.png");

	pad = &r.add<Image>("image-dpad", "resources/graphics/interface/DPad.png");
	pad->setAlphaMod(150);

	buttonA = &r.add<Image>("image-buttonA", "resources/graphics/interface/ButtonA.png");
	buttonA->setAlphaMod(150);

	buttonB = &r.add<Image>("image-buttonB", "resources/graphics/interface/ButtonA.png");
	buttonB->setAlphaMod(150);

	buttonMenu = &r.add<Image>("image-buttonMenu", "resources/graphics/interface/ButtonA.png");
	buttonMenu->setAlphaMod(150);
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

