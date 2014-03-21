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
		LuaActivity();
		~LuaActivity() {}
		
		void processInputs();
		void update();
		void render();
};

#endif // LUAACTIVITY_HPP_
