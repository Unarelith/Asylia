/*
 * =====================================================================================
 *
 *       Filename:  GameActivity.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/03/2014 18:19:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef GAMEACTIVITY_HPP_
#define GAMEACTIVITY_HPP_

class GameActivity : public Activity {
	public:
		GameActivity();
		~GameActivity() {}
		
		void processInputs();
		void update();
		void render();
};

#endif // GAMEACTIVITY_HPP_
