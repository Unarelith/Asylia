/*
 * =====================================================================================
 *
 *       Filename:  QuestInfoWindow.hpp
 *
 *    Description:
 *
 *        Created:  30/06/2014 18:50:09
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef QUESTINFOWINDOW_HPP_
#define QUESTINFOWINDOW_HPP_

#include <gk/graphics/Text.hpp>

#include "Quest.hpp"
#include "Window.hpp"

class QuestInfoWindow : public Window {
	public:
		QuestInfoWindow();

		void update();

		void setQuest(Quest *quest) { m_quest = quest; }

		enum Mode {
			ObjectivesMode,
			RewardsMode
		};

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		Quest *m_quest = nullptr;

		Mode m_mode;

		mutable gk::Text m_text{"font-default", 18}; // FIXME
};

#endif // QUESTINFOWINDOW_HPP_
