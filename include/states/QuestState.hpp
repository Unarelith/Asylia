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

#include "ApplicationState.hpp"
#include "CommandWindow.hpp"
#include "InfoWindow.hpp"
#include "Quest.hpp"
#include "QuestInfoWindow.hpp"

class QuestState : public ApplicationState {
	public:
		QuestState(ApplicationState *parent);
		~QuestState();

		void update();
		void render();

		enum Mode {
			CategoryChoice,
			QuestChoice
		};

	private:
		Mode m_mode;

		Quest *m_currentQuest;

		InfoWindow *m_questTitlewin;

		QuestInfoWindow m_questInfowin;

		CommandWindow *m_questCategorywin;
		CommandWindow *m_questListwin;
};

#endif // QUESTSTATE_HPP_
