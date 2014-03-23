/*
 * =====================================================================================
 *
 *       Filename:  MessageWindow.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  23/03/2014 18:33:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef MESSAGEWINDOW_HPP_
#define MESSAGEWINDOW_HPP_

class MessageWindow : public TextWindow {
	public:
		MessageWindow();
		~MessageWindow();
		
		void addMessage(std::string msg) { m_messages.push(msg); }
		
		void update();
		void draw();
		
		std::queue<std::string> messages() const { return m_messages; }
		
	private:
		std::queue<std::string> m_messages;
};

#endif // MESSAGEWINDOW_HPP_
