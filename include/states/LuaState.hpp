/*
 * =====================================================================================
 *
 *       Filename:  LuaState.hpp
 *
 *    Description:
 *
 *        Created:  21/03/2014 18:21:31
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef LUASTATE_HPP_
#define LUASTATE_HPP_

#include <string>

#include <gk/core/ApplicationState.hpp>

class LuaState : public gk::ApplicationState {
	public:
		LuaState(const std::string &filename, const std::string &table);

		void update() override;

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		std::string m_table;
};

#endif // LUASTATE_HPP_
