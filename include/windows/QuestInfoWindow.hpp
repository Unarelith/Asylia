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

#include "Quest.hpp"
#include "Window.hpp"

class QuestInfoWindow : public Window {
	public:
		QuestInfoWindow();

		void update();
		void draw(Quest *quest);

		enum Mode {
			ObjectivesMode,
			RewardsMode
		};

	private:
		Mode m_mode;
};

#endif // QUESTINFOWINDOW_HPP_
