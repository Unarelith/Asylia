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

Quest::Quest(u16 exp, u16 gold) {
	m_exp = exp;
	m_gold = gold;
}

Quest::~Quest() {
}

