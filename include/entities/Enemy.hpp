/*
 * =====================================================================================
 *
 *       Filename:  Enemy.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/04/2014 19:31:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef ENEMY_HPP_
#define ENEMY_HPP_

class Enemy : public Battler {
	public:
		Enemy(std::string name, std::string appearance, u8 level);
		~Enemy();
		
		std::string name() const { return _t(m_name); }
		
		Inventory *loot() { return &m_loot; }
		
	private:
		Inventory m_loot;
};

#endif // ENEMY_HPP_
