/*
 * =====================================================================================
 *
 *       Filename:  QuestActivity.hpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  30/06/2014 18:26:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef QUESTACTIVITY_HPP_
#define QUESTACTIVITY_HPP_

class QuestActivity : public Activity {
	public:
		QuestActivity(Activity *parent);
		~QuestActivity();

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

#endif // QUESTACTIVITY_HPP_
