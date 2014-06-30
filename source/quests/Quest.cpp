/*
 * =====================================================================================
 *
 *       Filename:  Quest.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29/06/2014 19:58:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

u16 Quest::counter = 0;

Quest::Quest(u16 exp, u16 gold) {
	m_id = counter;
	counter++;
	
	m_exp = exp;
	m_gold = gold;
	
	m_completed = false;
}

Quest::~Quest() {
	while(m_objectives.size() != 0) {
		delete m_objectives.back();
		m_objectives.pop_back();
	}
}

