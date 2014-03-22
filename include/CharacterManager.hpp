/*
 * =====================================================================================
 *
 *       Filename:  CharacterManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 20:21:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef CHARACTERMANAGER_HPP_
#define CHARACTERMANAGER_HPP_

namespace CharacterManager {
	void init();
	void free();
	
	extern Player *player;
}

#endif // CHARACTERMANAGER_HPP_
