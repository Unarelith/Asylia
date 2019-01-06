/*
 * =====================================================================================
 *
 *       Filename:  LuaActivity.hpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  21/03/2014 18:21:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef LUAACTIVITY_HPP_
#define LUAACTIVITY_HPP_

class LuaActivity : public Activity {
	public:
		LuaActivity(std::string filename, std::string table);
		~LuaActivity();

		void update();
		void render();

	private:
		std::string m_table;
};

#endif // LUAACTIVITY_HPP_
