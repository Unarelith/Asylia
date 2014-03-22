/*
 * =====================================================================================
 *
 *       Filename:  Interface.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 00:35:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef INTERFACE_HPP_
#define INTERFACE_HPP_

namespace Interface {
	void init();
	void free();
	
	extern Font *defaultFont;
	extern Image *interface;
};

#endif // INTERFACE_HPP_
