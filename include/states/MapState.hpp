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

#include <gk/core/ApplicationState.hpp>

#include "MapManager.hpp"

class MapState : public gk::ApplicationState {
	public:
		MapState();

		void update() override;
		void render() override;

	private:
		MapManager m_mapManager;
};

#endif // MAPSTATE_HPP_
