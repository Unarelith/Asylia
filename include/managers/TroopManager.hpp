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

namespace TroopManager {
	void init();
	void free();

	extern std::vector<Troop*> troops;
};

#endif // TROOPMANAGER_HPP_
