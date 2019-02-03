/*
 * =====================================================================================
 *
 *       Filename:  Timer.cpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 19:38:08
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Timer.hpp"

Timer::Timer() {
	m_t = SDL_GetTicks();
	m_isStarted = false;
	m_tick = 0;
}

Timer::~Timer() {
	reset();
	stop();
}

void Timer::stop() {
	if(m_isStarted) {
		m_isStarted = false;
		m_tick = SDL_GetTicks() - m_t;
	}
}

void Timer::start() {
	if(!m_isStarted) {
		m_isStarted = true;
		m_t = SDL_GetTicks() - m_tick;
	}
}

void Timer::reset() {
	m_t = SDL_GetTicks();
	m_isStarted = false;
	m_tick = 0;
}

