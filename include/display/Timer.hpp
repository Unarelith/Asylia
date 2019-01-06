/*
 * =====================================================================================
 *
 *       Filename:  Timer.hpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  22/03/2014 19:37:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef TIMER_HPP_
#define TIMER_HPP_

class Timer {
	public:
		Timer();
		~Timer();

		void stop();
		void start();
		void reset();

		bool isStarted() const { return m_isStarted; }

		u16 time() { return (m_isStarted) ? SDL_GetTicks() - m_t : m_tick; }

	private:
		u16 m_t;

		bool m_isStarted;

		u16 m_tick;
};

#endif // TIMER_HPP_
