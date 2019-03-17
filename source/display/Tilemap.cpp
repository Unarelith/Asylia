/*
 * =====================================================================================
 *
 *       Filename:  Tilemap.cpp
 *
 *    Description:
 *
 *        Created:  17/03/2019 12:34:23
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Tilemap.hpp"

void Tilemap::addEvent(Event *event) {
	m_events.emplace(event->name(), event);
}

Event *Tilemap::getEvent(const std::string &name) {
	auto it = m_events.find(name);
	if (it != m_events.end())
		return it->second;
	return nullptr;
}

void Tilemap::updateEvents() {
	for (auto &it : m_events) {
		it.second->update();
	}
}

void Tilemap::updateEventsActions() {
	for (auto &it : m_events) {
		it.second->updateActions();
	}
}

void Tilemap::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	gk::Tilemap::draw(target, states);

	for (auto &it : m_events)
		target.draw(*it.second, states);
}

