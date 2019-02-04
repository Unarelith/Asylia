/*
 * =====================================================================================
 *
 *       Filename:  Troop.cpp
 *
 *    Description:
 *
 *        Created:  11/06/2014 15:32:37
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Troop.hpp"

Troop::Troop(const std::string &battleback) {
	if (!battleback.empty()) {
		m_battleback.reload(battleback.c_str());
		m_isBattlebackLoaded = true;
	}
}

