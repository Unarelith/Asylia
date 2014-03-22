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

Font *Interface::defaultFont = NULL;
Image *Interface::interface = NULL;

void Interface::init() {
	defaultFont = new Font("fonts/arial.ttf");
	
	interface = new Image("graphics/interface/Interface.png");
}

void Interface::free() {
	delete interface;
	
	delete defaultFont;
}

