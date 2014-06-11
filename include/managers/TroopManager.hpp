/*
 * =====================================================================================
 *
 *       Filename:  TroopManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27/04/2014 21:09:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
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
