/*
 * =====================================================================================
 *
 *       Filename:  TroopManager.hpp
 *
 *    Description:
 *
 *        Created:  27/04/2014 21:09:54
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TROOPMANAGER_HPP_
#define TROOPMANAGER_HPP_

#include <memory>

#include "Troop.hpp"

class TroopManager : public Singleton<TroopManager> {
	public:
		void init();

		Troop *getTroop(size_t i) { return m_troops[i].get(); }

	private:
		std::vector<std::unique_ptr<Troop>> m_troops;
};

#endif // TROOPMANAGER_HPP_
