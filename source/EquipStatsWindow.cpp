/*
 * =====================================================================================
 *
 *       Filename:  EquipStatsWindow.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/04/2014 17:29:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

EquipStatsWindow::EquipStatsWindow() : Window(150, 52, (GameWindow::main->width() - 150) / 2, (GameWindow::main->height() - 52) / 2) {
}

EquipStatsWindow::~EquipStatsWindow() {
}

void EquipStatsWindow::draw(Item *currentItem) {
	u16 baseAtk, finalAtk, baseDef, finalDef;
	Color finalAtkColor(Color::white), finalDefColor(Color::white);
	Image level, arrow, baseAtkImg, finalAtkImg, baseDefImg, finalDefImg;
	
	baseAtk = CharacterManager::player->battler()->totalAtk();
	baseDef = CharacterManager::player->battler()->totalDef();
	
	if(currentItem && currentItem->type() != Item::Type::BasicItem) {
		if(currentItem->type() == Item::Type::Armor) {
			finalAtk = baseAtk;
			Armor *armor = CharacterManager::player->inventory()->armor(((Armor*)currentItem)->slot());
			if(armor) finalDef = CharacterManager::player->battler()->totalDef() - armor->def() + ((Armor*)currentItem)->def();
			else finalDef = CharacterManager::player->battler()->totalDef() + ((Armor*)currentItem)->def();
			
			if(finalDef > baseDef) {
				finalDefColor = Color::green;
			}
			else if(finalDef < baseDef) {
				finalDefColor = Color::red;
			}
		} else {
			finalAtk = CharacterManager::player->battler()->atk() + ((Weapon*)currentItem)->atk();
			finalDef = baseDef;
			
			if(finalAtk > baseAtk) {
				finalAtkColor = Color::green;
			}
			else if(finalAtk < baseAtk) {
				finalAtkColor = Color::red;
			}
		}
	} else {
		finalAtk = baseAtk;
		finalDef = baseDef;
	}
	
	Window::draw();
	
	Interface::defaultFont->printScaled(CharacterManager::player->battler()->name().c_str(), m_x + GameWindow::main->viewportX() + 20, m_y + GameWindow::main->viewportY() + 20, m_width - 130, 32, FONT_LARGE);
	
	Interface::defaultFont->printScaled(_t("Lv").c_str(), m_x + GameWindow::main->viewportX() + m_width - 90, m_y + GameWindow::main->viewportY() + 20, 25, 32, FONT_LARGE, Color::system);
	Interface::defaultFont->printToImage(to_string(CharacterManager::player->battler()->level()).c_str(), m_x + GameWindow::main->viewportX() + m_width - 20, m_y + GameWindow::main->viewportY() + 20, &level, FONT_LARGE);
	level.render(level.posRect().x - level.width());
	
	Interface::defaultFont->printToImage("->", GameWindow::main->viewportX(), m_y + GameWindow::main->viewportY() + 52, &arrow, FONT_LARGE, Color::system);
	
	Interface::defaultFont->printScaled(_t("ATK").c_str(), m_x + GameWindow::main->viewportX() + 20, m_y + GameWindow::main->viewportY() + 52, 60, 32, FONT_LARGE, Color::system);
	Interface::defaultFont->printToImage(to_string(baseAtk).c_str(), GameWindow::main->viewportX(), m_y + GameWindow::main->viewportY() + 52, &baseAtkImg, FONT_LARGE);
	Interface::defaultFont->printToImage(to_string(finalAtk).c_str(), m_x + GameWindow::main->viewportX() + m_width - 20, m_y + GameWindow::main->viewportY() + 52, &finalAtkImg, FONT_LARGE, finalAtkColor);
	
	Interface::defaultFont->printScaled(_t("DEF").c_str(), m_x + GameWindow::main->viewportX() + 20, m_y + GameWindow::main->viewportY() + 84, 60, 32, FONT_LARGE, Color::system);
	Interface::defaultFont->printToImage(to_string(baseDef).c_str(), GameWindow::main->viewportX(), m_y + GameWindow::main->viewportY() + 84, &baseDefImg, FONT_LARGE);
	Interface::defaultFont->printToImage(to_string(finalDef).c_str(), m_x + GameWindow::main->viewportX() + m_width - 20, m_y + GameWindow::main->viewportY() + 84, &finalDefImg, FONT_LARGE, finalDefColor);
	
	finalAtkImg.render(finalAtkImg.posRect().x - finalAtkImg.width());
	finalDefImg.render(finalDefImg.posRect().x - finalDefImg.width());
	
	if(CharacterManager::player->battler()->atk() > CharacterManager::player->battler()->def()) {
		arrow.render(finalAtkImg.posRect().x - arrow.width() - 8);
		arrow.render(-1, arrow.posRect().y + 32);
	} else {
		arrow.render(finalDefImg.posRect().x - arrow.width() - 8, arrow.posRect().y + 32);
		arrow.render(-1, arrow.posRect().y - 32);
	}
	
	baseAtkImg.render(arrow.posRect().x - baseAtkImg.width() - 10);
	baseDefImg.render(arrow.posRect().x - baseDefImg.width() - 10);
}

