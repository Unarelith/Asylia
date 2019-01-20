/*
 * =====================================================================================
 *
 *       Filename:  Interface.hpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 00:35:05
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef INTERFACE_HPP_
#define INTERFACE_HPP_

namespace Interface {
	void init();
	void free();

	void renderPad();
	void renderHUD();

	extern Font *defaultFont;
	extern Image *interface;

	extern Image *pad;
	extern Image *buttonA;
	extern Image *buttonB;
	extern Image *buttonMenu;
};

#endif // INTERFACE_HPP_
