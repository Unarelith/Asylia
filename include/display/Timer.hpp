/*
 * =====================================================================================
 *
 *       Filename:  Timer.hpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 19:37:18
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
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
