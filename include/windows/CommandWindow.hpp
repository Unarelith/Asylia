/*
 * =====================================================================================
 *
 *       Filename:  CommandWindow.hpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 13:13:37
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef COMMANDWINDOW_HPP_
#define COMMANDWINDOW_HPP_

#include <gk/graphics/Text.hpp>

#include "SelectableWindow.hpp"

class Command {
	public:
		Command(const std::string &text, bool isEnabled, u16 x, u16 y)
			: m_text{_t(text), "font-default", 18}, m_isEnabled(isEnabled)
		{
			m_text.setPosition(x, y);
		}

		const gk::Text &text() const { return m_text; }

		bool isEnabled() const { return m_isEnabled; }

	private:
		gk::Text m_text;

		bool m_isEnabled = true;
};

class CommandWindow : public SelectableWindow {
	public:
		CommandWindow(s16 x, s16 y, u16 width, bool horizontal = false, bool centered = false);
		CommandWindow(u16 width);

		void clear() {
			m_commands.clear();

			m_height = (m_horizontal) ? 64 : 32;
			m_itemMax = 0;
		}

		void addCommand(const std::string &cmd, bool disabled = false) {
			if(!m_horizontal)
				m_height += 32;

			m_commands.emplace_back(cmd, !disabled, 22, 22 + 32 * m_commands.size());

			m_itemMax++;
		}

		bool disabled(u8 pos) const { return !m_commands[pos].isEnabled(); }

		const std::vector<Command> &commands() { return m_commands; }

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		std::vector<Command> m_commands;

		bool m_horizontal;
		bool m_centered;
};

#endif // COMMANDWINDOW_HPP_
