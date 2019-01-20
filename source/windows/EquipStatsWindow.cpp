/*
 * =====================================================================================
 *
 *       Filename:  EquipStatsWindow.cpp
 *
 *    Description:
 *
 *        Created:  13/04/2014 17:29:09
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

EquipStatsWindow::EquipStatsWindow(Actor *actor) : Window(150, 52, (GameWindow::main->width() - 150) / 2, (GameWindow::main->height() - 52) / 2) {
	m_actor = actor;
}

EquipStatsWindow::~EquipStatsWindow() {
}

void EquipStatsWindow::draw(Item *currentItem) {
	u16 baseAtk, finalAtk, baseDef, finalDef;
	Color finalAtkColor(Color::white), finalDefColor(Color::white);
	Image arrow, baseAtkImg, finalAtkImg, baseDefImg, finalDefImg;

	baseAtk = m_actor->totalAtk();
	baseDef = m_actor->totalDef();

	if(currentItem && currentItem->type() != Item::Type::BasicItem) {
		if(currentItem->type() == Item::Type::Armor) {
			finalAtk = baseAtk;
			Armor *armor = m_actor->equipment()->armor(((Armor*)currentItem)->slot());
			if(armor) finalDef = m_actor->totalDef() - armor->def() + ((Armor*)currentItem)->def();
			else finalDef = m_actor->totalDef() + ((Armor*)currentItem)->def();

			if(finalDef > baseDef) {
				finalDefColor = Color::green;
			}
			else if(finalDef < baseDef) {
				finalDefColor = Color::red;
			}
		} else {
			finalAtk = m_actor->atk() + ((Weapon*)currentItem)->atk();
			finalDef = baseDef;

			if(finalAtk > baseAtk) {
				finalAtkColor = Color::green;
			}
			else if(finalAtk < baseAtk) {
				finalAtkColor = Color::red;
			}
		}
	}
	else if(((EquipActivity*)ActivityManager::top())->itemMode()) {
		if(((EquipActivity*)ActivityManager::top())->choicewinPos() == 0) {
			finalAtk = m_actor->atk();
			finalDef = baseDef;

			finalAtkColor = Color::red;
		} else {
			finalAtk = baseAtk;
			finalDef = baseDef - m_actor->equipment()->armor(((EquipActivity*)ActivityManager::top())->choicewinPos() - 1)->def();

			finalDefColor = Color::red;
		}
	} else {
		finalAtk = baseAtk;
		finalDef = baseDef;
	}

	Window::draw();

	printName(m_actor, 20, 20, m_width - 130);
	printLevel(m_actor, m_width - 90, 20, m_width - 20);

	Interface::defaultFont->printToImage("->", 0, m_y + 52, &arrow, FONT_LARGE, Color::system);

	Interface::defaultFont->printScaled(_t("ATK").c_str(), m_x + 20, m_y + 52, 60, 32, FONT_LARGE, Color::system);
	Interface::defaultFont->printToImage(to_string(baseAtk).c_str(), 0, m_y + 52, &baseAtkImg, FONT_LARGE);
	Interface::defaultFont->printToImage(to_string(finalAtk).c_str(), m_x + m_width - 20, m_y + 52, &finalAtkImg, FONT_LARGE, finalAtkColor);

	Interface::defaultFont->printScaled(_t("DEF").c_str(), m_x + 20, m_y + 84, 60, 32, FONT_LARGE, Color::system);
	Interface::defaultFont->printToImage(to_string(baseDef).c_str(), 0, m_y + 84, &baseDefImg, FONT_LARGE);
	Interface::defaultFont->printToImage(to_string(finalDef).c_str(), m_x + m_width - 20, m_y + 84, &finalDefImg, FONT_LARGE, finalDefColor);

	finalAtkImg.render(finalAtkImg.posRect().x - finalAtkImg.width());
	finalDefImg.render(finalDefImg.posRect().x - finalDefImg.width());

	if(m_actor->atk() > m_actor->def()) {
		arrow.render(finalAtkImg.posRect().x - arrow.width() - 8);
		arrow.render(-1, arrow.posRect().y + 32);
	} else {
		arrow.render(finalDefImg.posRect().x - arrow.width() - 8, arrow.posRect().y + 32);
		arrow.render(-1, arrow.posRect().y - 32);
	}

	baseAtkImg.render(arrow.posRect().x - baseAtkImg.width() - 10);
	baseDefImg.render(arrow.posRect().x - baseDefImg.width() - 10);
}

