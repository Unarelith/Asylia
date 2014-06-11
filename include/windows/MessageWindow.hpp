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
		
		void addMessage(std::string msg) { m_messages.push_back(msg); }
		void addCommand(std::string msg) { m_cmdwin->addCommand(msg); }
		
		void update();
		void updateCmdwinSize();
		
		void draw();
		
		void eraseCurrentMessage() { m_messages.erase(m_messages.begin()); }
		
		std::vector<std::string> messages() const { return m_messages; }
		
	private:
		std::vector<std::string> m_messages;
		
		CommandWindow *m_cmdwin;
		
		bool m_choiceMode;
};

#endif // MESSAGEWINDOW_HPP_
