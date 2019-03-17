/*
 * =====================================================================================
 *
 *       Filename:  Tilemap.hpp
 *
 *    Description:
 *
 *        Created:  17/03/2019 12:30:50
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TILEMAP_HPP_
#define TILEMAP_HPP_

#include <unordered_map>

#include <gk/graphics/Tilemap.hpp>

#include "Event.hpp"

class Tilemap : public gk::Tilemap {
	public:
		Tilemap(u16 width, u16 height, gk::Tileset &tileset, const std::vector<std::vector<u16>> &data)
			: gk::Tilemap(width, height, tileset, data) {}

		void addEvent(Event *event);
		Event *getEvent(const std::string &name);

		void initEvents();
		void updateEvents();
		void updateEventsActions();

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		std::unordered_map<std::string, Event*> m_events;
};

#endif // TILEMAP_HPP_
