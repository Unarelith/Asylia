/*
 * =====================================================================================
 *
 *       Filename:  MessageState.hpp
 *
 *    Description:
 *
 *        Created:  21/03/2014 18:19:08
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MESSAGESTATE_HPP_
#define MESSAGESTATE_HPP_

#include <memory>

#include <gk/core/ApplicationState.hpp>
#include <gk/core/IntTypes.hpp>

#include "CommandWindow.hpp"
#include "TextWindow.hpp"

class MessageState : public gk::ApplicationState {
	public:
		MessageState(const std::string &message, gk::ApplicationState *parent = nullptr);

		void addCommand(const std::string &command) { m_cmdwin->addCommand(command); updateCmdwinSize(); }

		void updateCmdwinSize();

		u16 getCmdwinPos() { return m_cmdwin->pos(); }

		void update();
		void render();

	private:
		std::unique_ptr<TextWindow> m_txtwin;
		std::unique_ptr<CommandWindow> m_cmdwin;

		std::string m_message;
};

#endif // MESSAGESTATE_HPP_
