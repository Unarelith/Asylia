/*
 * =====================================================================================
 *
 *       Filename:  EquipChoiceWindow.cpp
 *
 *    Description:
 *
 *        Created:  17/04/2014 20:45:29
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Color.hpp"
#include "Config.hpp"
#include "EquipChoiceWindow.hpp"
#include "ResourceHelper.hpp"

EquipChoiceWindow::EquipChoiceWindow(Equipment *equipment) : SelectableWindow(150 + (SCREEN_WIDTH - 150) / 2, 52, (SCREEN_WIDTH - 150) / 2, (SCREEN_HEIGHT - 52) / 2) {
	m_itemMax = 4;
	m_columnMax = 1;

	m_pos = 0;

	m_equipment = equipment;
}

void EquipChoiceWindow::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	Window::draw(target, states);

	states.transform *= getTransform();

	if(!m_equipment->weapon()) {
		// FIXME
		// ResourceHelper::getWeapon(0)->thumbnail().render(m_x + 20, m_y + 20);

		m_text.setString(_t("Empty"));
		m_text.setColor(Color::System);
		m_text.setStyle(gk::Text::Italic);
		m_text.setPosition(48, 20);
		target.draw(m_text, states);
	} else {
		// m_equipment->weapon()->thumbnail().render(m_x + 20, m_y + 20);
		m_equipment->weapon()->thumbnail().setPosition(20, 20);
		target.draw(m_equipment->weapon()->thumbnail(), states);

		m_text.setString(m_equipment->weapon()->name());
		m_text.setStyle(gk::Text::Normal);
		m_text.setColor(gk::Color::White);
		m_text.setPosition(48, 20);
		target.draw(m_text, states);
	}

	for(u8 slot = 0 ; slot < 3 ; slot++) {
		Armor *armor = m_equipment->armor(slot);
		if(!armor) {
			// for(auto &it : ResourceHelper::getInstance().armors()) {
			// 	if(it->slot() == slot) {
			// 		it->thumbnail().render(m_x + 20, m_y + 52 + slot * 32);
			// 		break;
			// 	}
			// }

			m_text.setString(_t("Empty"));
			m_text.setColor(Color::System);
			m_text.setStyle(gk::Text::Italic);
			m_text.setPosition(48, 52 + slot * 32);
			target.draw(m_text, states);

			// ResourceHelper::getFont("default").setStyle(FONT_LARGE, TTF_STYLE_ITALIC);
			// ResourceHelper::getFont("default").printScaled(_t("Empty").c_str(), m_x + 48, m_y + 52 + slot * 32, m_width - 40, 32, FONT_LARGE, Color::System);
			// ResourceHelper::getFont("default").setStyle(FONT_LARGE, TTF_STYLE_NORMAL);
		} else {
			// armor->thumbnail().render(m_x + 20, m_y + 52 + slot * 32);
			armor->thumbnail().setPosition(20, 52 + slot * 32);
			target.draw(armor->thumbnail(), states);


			m_text.setString(armor->name());
			m_text.setStyle(gk::Text::Normal);
			m_text.setColor(gk::Color::White);
			m_text.setPosition(48, 52 + slot * 32);
			target.draw(m_text, states);

			// ResourceHelper::getFont("default").printScaled(armor->name().c_str(), m_x + 48, m_y + 52 + slot * 32, m_width - 40, 32, FONT_LARGE);
		}
	}
}

