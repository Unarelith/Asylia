/*
 * =====================================================================================
 *
 *       Filename:  Activity.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/03/2014 21:01:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef ACTIVITY_HPP_
#define ACTIVITY_HPP_

class Activity {
	public:
		Activity() {}
		~Activity() {}
		
		virtual void processInputs() = 0;
		virtual void update() = 0;
		virtual void render() = 0;
		
		void pollEvents(bool *quit = NULL);
};

class GameActivity : public Activity {
	public:
		GameActivity() {}
		~GameActivity() {}
		
		void processInputs();
		void update();
		void render();
};

class MenuActivity : public Activity {
	public:
		MenuActivity() {}
		~MenuActivity() {}
		
		void processInputs();
		void update();
		void render();
};

class DialogActivity : public GameActivity {
	public:
		DialogActivity() {}
		~DialogActivity() {}
		
		void processInputs();
		void update();
		void render();
};

#endif // ACTIVITY_HPP_
