/*
 * =====================================================================================
 *
 *       Filename:  MessageActivity.hpp
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
#ifndef MESSAGEACTIVITY_HPP_
#define MESSAGEACTIVITY_HPP_

class MessageActivity : public Activity {
	public:
		MessageActivity(std::string message, Activity *parent = NULL);
		~MessageActivity();
		
		void update();
		void render();
		
	private:
		TextWindow *m_txtwin;
		
		std::string m_message;
};

#endif // MESSAGEACTIVITY_HPP_
