/*
 * =====================================================================================
 *
 *       Filename:  Timer.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 19:38:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

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

