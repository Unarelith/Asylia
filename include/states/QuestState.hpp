/*
 * =====================================================================================
 *
 *       Filename:  QuestState.hpp
 *
 *    Description:
 *
 *        Created:  30/06/2014 18:26:06
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef QUESTSTATE_HPP_
#define QUESTSTATE_HPP_

#include <gk/core/ApplicationState.hpp>

#include "CommandWindow.hpp"
#include "Config.hpp"
#include "InfoWindow.hpp"
#include "Quest.hpp"
#include "QuestInfoWindow.hpp"

class QuestState : public gk::ApplicationState {
	public:
		QuestState(gk::ApplicationState *parent);

		void update() override;
		void render() override;

		enum Mode {
			CategoryChoice,
			QuestChoice
		};

	private:
		Mode m_mode;

		Quest *m_currentQuest = nullptr;

		InfoWindow m_questTitlewin{0, 0, SCREEN_WIDTH, 52};

		QuestInfoWindow m_questInfowin;

		CommandWindow m_questCategorywin{0, 52, SCREEN_WIDTH, true, true};
		CommandWindow m_questListwin{0, 116, 200};
};

#endif // QUESTSTATE_HPP_
