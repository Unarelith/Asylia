/*
 * =====================================================================================
 *
 *       Filename:  Enemy.hpp
 *
 *    Description:
 *
 *        Created:  22/04/2014 19:31:35
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include "Battler.hpp"
#include "Inventory.hpp"

class Enemy : public Battler {
	public:
		Enemy(std::string name, std::string appearance, u8 level);

		std::string name() const { return _t(m_name); }

		Inventory *loot() { return &m_loot; }

	private:
		Inventory m_loot;
};

#endif // ENEMY_HPP_
