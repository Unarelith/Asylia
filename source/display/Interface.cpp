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

Font *Interface::defaultFont = nullptr;
Image *Interface::interface = nullptr;

void Interface::init() {
	auto &r = gk::ResourceHandler::getInstance();

	defaultFont = &r.add<Font>("font-default", "resources/fonts/arial.ttf");

	interface = &r.add<Image>("image-interface", "resources/graphics/interface/Interface.png");
}

