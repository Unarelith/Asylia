/*
 * =====================================================================================
 *
 *       Filename:  Battle.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  23/04/2014 18:05:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Battle::Battle(std::string battleback) {
	m_battleback = new Image(battleback.c_str());
}

Battle::~Battle() {
	delete m_battleback;
	
	while(m_actors.size() != 0) {
		delete m_actors.back();
		m_actors.pop_back();
	}
	
	while(m_enemies.size() != 0) {
		delete m_enemies.back();
		m_enemies.pop_back();
	}
}

void Battle::drawArrow(Battler *battler) {
	s16 x, y;
	u16 width, height;
	
	width = battler->image()->posRect().w;
	height = battler->image()->posRect().h;
	
	x = battler->image()->posRect().x + width / 2 - 16;
	y = battler->image()->posRect().y + height / 2;
	
	Interface::interface->render(x, y, 32, 32, 128 + 32 * (SDL_GetTicks() / 4 % 2), 96, 32, 32);
}

