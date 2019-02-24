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
		Enemy(const std::string &name, const std::string &appearance, u8 level);

		const std::string &name() const { return _t(m_name); }

		Inventory &loot() { return m_loot; }

	private:
		Inventory m_loot;
};

#endif // ENEMY_HPP_
