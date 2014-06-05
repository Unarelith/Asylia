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

class DialogActivity : public Activity {
	public:
		DialogActivity(Activity *parent = NULL);
		~DialogActivity();
		
		void addMessage(std::string msg) { m_msgwin->addMessage(msg); }
		void clearMessages() { while(m_msgwin->messages().size() != 0) m_msgwin->messages().pop(); }
		
		void update();
		void render();
		
	private:
		MessageWindow *m_msgwin;
};

#endif // DIALOGACTIVITY_HPP_
