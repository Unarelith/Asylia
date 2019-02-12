/*
 * =====================================================================================
 *
 *       Filename:  LuaHandler.hpp
 *
 *    Description:
 *
 *        Created:  21/03/2014 23:46:58
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef LUAHANDLER_HPP_
#define LUAHANDLER_HPP_

#include <string>

#include <sol.hpp>

#include "Singleton.hpp"

class LuaHandler : public Singleton<LuaHandler> {
	public:
		void init();

		void bindClasses();

		void doFile(const char *filename);
		void doString(const std::string &str);

	private:
		sol::state m_lua;
};

#endif // LUAHANDLER_HPP_
