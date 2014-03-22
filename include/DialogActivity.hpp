/*
 * =====================================================================================
 *
 *       Filename:  DialogActivity.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/03/2014 18:19:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef DIALOGACTIVITY_HPP_
#define DIALOGACTIVITY_HPP_

class DialogActivity : public MapActivity {
	public:
		DialogActivity();
		~DialogActivity();
		
		void update();
		void render();
};

#endif // DIALOGACTIVITY_HPP_
