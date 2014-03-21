/*
 * =====================================================================================
 *
 *       Filename:  MenuActivity.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/03/2014 18:21:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef MENUACTIVITY_HPP_
#define MENUACTIVITY_HPP_

class MenuActivity : public Activity {
	public:
		MenuActivity() {}
		~MenuActivity() {}
		
		void processInputs();
		void update();
		void render();
};

#endif // MENUACTIVITY_HPP_
