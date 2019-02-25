/*
 * =====================================================================================
 *
 *       Filename:  QuestInfoWindow.cpp
 *
 *    Description:
 *
 *        Created:  30/06/2014 18:52:20
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/input/GamePad.hpp>

#include "Color.hpp"
#include "Config.hpp"
#include "GameKey.hpp"
#include "QuestInfoWindow.hpp"
#include "ResourceHelper.hpp"

QuestInfoWindow::QuestInfoWindow() : Window(200, 116, SCREEN_WIDTH - 200, SCREEN_HEIGHT - 116) {
	m_mode = Mode::ObjectivesMode;
}

void QuestInfoWindow::update() {
	if(gk::GamePad::isKeyPressedOnce(GameKey::A)) {
		if(m_mode == Mode::ObjectivesMode) m_mode = Mode::RewardsMode;
		else if(m_mode == Mode::RewardsMode) m_mode = Mode::ObjectivesMode;
	}
}

void QuestInfoWindow::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	Window::draw(target, states);

	states.transform *= getTransform();

	// drawWindow(m_x, m_y, m_width, 64);
	// drawWindow(m_x, m_y + 64, m_width, 134);
    //
	// if(m_mode == Mode::ObjectivesMode) {
	// 	drawWindow(m_x, m_y + 198, m_width, m_height - 198);
	// }
	// else if(m_mode == Mode::RewardsMode) {
	// 	drawWindow(m_x, m_y + 198, m_width / 2, m_height - 198);
	// 	drawWindow(m_x + m_width / 2, m_y + 198, m_width / 2, m_height - 198);
	// }

	if(m_quest) {
		std::string questName = _t("Quest" + std::to_string(m_quest->id()));
		std::string questDesc = "    " + _t("Quest" + std::to_string(m_quest->id()) + "Desc");

		m_text.setCharacterSize(22);
		m_text.setText(questName);
		m_text.setPosition(0, 0);
		m_text.setColor(gk::Color::White);
		m_text.setSize({static_cast<int>(SCREEN_WIDTH - x()), 64});
		m_text.setWrapped(false);
		m_text.setCentered(true);
		target.draw(m_text, states);

		m_text.setCharacterSize(18);
		m_text.setText(_t("Description") + ":");
		m_text.setPosition(20, 80);
		m_text.setColor(Color::System);
		m_text.setWrapped(false);
		m_text.setCentered(false);
		target.draw(m_text, states);

		m_text.setCharacterSize(18);
		m_text.setText(questDesc);
		m_text.setPosition(30, 110);
		m_text.setColor(gk::Color::White);
		m_text.setSize({m_width - 60, 64});
		m_text.setWrapped(true);
		m_text.setCentered(false);
		target.draw(m_text, states);

		if(m_mode == Mode::ObjectivesMode) {
			m_text.setCharacterSize(18);
			m_text.setText(_t("Objectives") + ":");
			m_text.setPosition(20, 214);
			m_text.setColor(Color::System);
			m_text.setWrapped(false);
			m_text.setCentered(false);
			target.draw(m_text, states);

			for(auto it : m_quest->objectives()) {
				std::string objectiveDesc = "- " + _t("Quest" + std::to_string(m_quest->id()) + "_Obj" + std::to_string(it->id()) + "Desc");

				m_text.setCharacterSize(18);
				m_text.setText(objectiveDesc);
				m_text.setPosition(30, 242 + 28 * it->id());
				m_text.setColor(gk::Color::White);
				m_text.setWrapped(false);
				m_text.setCentered(false);
				target.draw(m_text, states);

				// printStat(0, 242 + 28 * it->id(), " ", 1, 0, m_width - 30, 5);
			}
		}
		else if(m_mode == Mode::RewardsMode) {
			m_text.setCharacterSize(18);
			m_text.setText(_t("Rewards") + ":");
			m_text.setPosition(20, 214);
			m_text.setColor(Color::System);
			m_text.setWrapped(false);
			m_text.setCentered(false);
			target.draw(m_text, states);

			// printStat(30, 260, _t("EXP"), quest->exp(), 60, m_width / 2 - 40);
			// printStat(30, 292, _t("Gold"), quest->gold(), 60, m_width / 2 - 40);

			m_text.setCharacterSize(18);
			m_text.setText(_t("Items") + ":");
			m_text.setPosition(m_width / 2 + 20, 214);
			m_text.setColor(Color::System);
			m_text.setWrapped(false);
			m_text.setCentered(false);
			target.draw(m_text, states);

			// u16 j = 0;
			// for(u16 i = 0 ; i < quest->items()->nbItems() ; i++) {
			// 	printItem(quest->items()->getItem(i), quest->items()->getItemCount(i), m_width / 2 + 30, 242 + j * 28, m_width / 2 - 50);
			// 	j++;
			// }
			// for(u16 i = 0 ; i < quest->items()->nbArmors() ; i++) {
			// 	printItem(quest->items()->getArmor(i), quest->items()->getArmorCount(i), m_width / 2 + 30, 242 + j * 28, m_width / 2 - 50);
			// 	j++;
			// }
			// for(u16 i = 0 ; i < quest->items()->nbWeapons() ; i++) {
			// 	printItem(quest->items()->getWeapon(i), quest->items()->getWeaponCount(i), m_width / 2 + 30, 242 + j * 28, m_width / 2 - 50);
			// 	j++;
			// }
		}
	}
}

