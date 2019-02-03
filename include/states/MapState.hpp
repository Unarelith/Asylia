/*
 * =====================================================================================
 *
 *       Filename:  MapState.hpp
 *
 *    Description:
 *
 *        Created:  21/03/2014 18:19:43
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MAPSTATE_HPP_
#define MAPSTATE_HPP_

#include "ApplicationState.hpp"

class MapState : public ApplicationState {
	public:
		MapState();
		~MapState();

		void init();

		void update();
		void render();
};

#endif // MAPSTATE_HPP_
