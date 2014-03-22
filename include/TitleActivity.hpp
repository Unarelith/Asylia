/*
 * =====================================================================================
 *
 *       Filename:  TitleActivity.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 17:18:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef TITLEACTIVITY_HPP_
#define TITLEACTIVITY_HPP_

class TitleActivity : public Activity {
	public:
		TitleActivity();
		~TitleActivity();
		
		void update();
		void render();
		
	private:
		Image *m_background;
		CommandWindow *m_cmdwin;
};

#endif // TITLEACTIVITY_HPP_
