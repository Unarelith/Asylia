/*
 * =====================================================================================
 *
 *       Filename:  LuaActivity.hpp
 *
 *    Description:
 *
 *        Created:  21/03/2014 18:21:31
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
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
