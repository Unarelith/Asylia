/*
 * =====================================================================================
 *
 *       Filename:  EndActivity.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 17:46:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef ENDACTIVITY_HPP_
#define ENDACTIVITY_HPP_

class EndActivity : public Activity {
	public:
		EndActivity(bool disableCancel = false);
		~EndActivity();
		
		void update();
		void render();
		
	private:
		CommandWindow *m_cmdwin;
};

#endif // ENDACTIVITY_HPP_
