/*
 * =====================================================================================
 *
 *       Filename:  Singleton.hpp
 *
 *    Description:
 *
 *        Created:  04/02/2019 20:48:41
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SINGLETON_HPP_
#define SINGLETON_HPP_

template<typename T>
class Singleton {
	public:
		static T &getInstance() { return *s_instance; }
		static void setInstance(T &instance) { s_instance = &instance; }

	private:
		static T *s_instance;
};

#endif // SINGLETON_HPP_
