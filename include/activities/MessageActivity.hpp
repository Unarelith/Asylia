/*
 * =====================================================================================
 *
 *       Filename:  MessageActivity.hpp
 *
 *    Description:
 *
 *        Created:  21/03/2014 18:19:08
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MESSAGEACTIVITY_HPP_
#define MESSAGEACTIVITY_HPP_

class MessageActivity : public Activity {
	public:
		MessageActivity(std::string message, Activity *parent = NULL);
		~MessageActivity();

		void addCommand(std::string command) { m_cmdwin->addCommand(command); updateCmdwinSize(); }

		void updateCmdwinSize();

		u16 getCmdwinPos() { return m_cmdwin->pos(); }

		void update();
		void render();

	private:
		TextWindow *m_txtwin;

		CommandWindow *m_cmdwin;

		std::string m_message;
};

#endif // MESSAGEACTIVITY_HPP_
