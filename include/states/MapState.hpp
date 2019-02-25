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
#include <gk/graphics/Tilemap.hpp>

class MapState : public gk::ApplicationState {
	public:
		MapState();

		void update() override;

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		gk::Tilemap *m_currentMap = nullptr;
};

#endif // MAPSTATE_HPP_
