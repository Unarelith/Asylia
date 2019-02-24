/*
 * =====================================================================================
 *
 *       Filename:  VictoryWindow.cpp
 *
 *    Description:
 *
 *        Created:  31/05/2014 16:20:55
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/audio/AudioPlayer.hpp>

#include "Config.hpp"
#include "Player.hpp"
#include "ResourceHelper.hpp"
#include "VictoryWindow.hpp"

VictoryWindow::VictoryWindow() : Window(SCREEN_WIDTH / 2 - 100, 0, 200, 150) {
}

void VictoryWindow::init(Battle *battle) {
	m_battle = battle;

	for(auto &it : m_battle->enemies()) {
		m_inventory.add(&it.second->loot(), true);
	}

	m_itemsNb = m_inventory.nbItems() + m_inventory.nbArmors() + m_inventory.nbWeapons();

	ResourceHelper::getPlayer()->inventory()->add(&m_inventory);

	for(u8 i = 0 ; i < ResourceHelper::getPlayer()->teamSize() ; i++) {
		ResourceHelper::getPlayer()->getTeamMember(i)->gainExp(m_battle->exp() / m_battle->actors().size());
	}

	ResourceHelper::getPlayer()->gainGold(m_battle->gold());

	gk::AudioPlayer::playSound("sound-confirm");
}

void VictoryWindow::draw() {
	m_height = 134 + 32 * m_itemsNb;

	// FIXME
	// m_y = 319 / 2 - m_height / 2; // SCREEN_HEIGHT - 319 = ActorStatsWindow->height()

	Window::draw();

	// FIXME
	// ResourceHelper::getFont("default").printCentered(_t("Victory").c_str(), m_x, m_y + 20, m_width, 21, FONT_LARGE);
	// printStat(20, 52, _t("EXP"), m_battle->exp(), 60, 180);
	// printStat(20, 84, _t("Gold"), m_battle->gold(), 60, 180);
    //
	// u16 i = 0;
	// for(u16 j = 0 ; j < m_inventory.nbItems() ; j++) {
	// 	printItem(m_inventory.getItem(j), m_inventory.getItemCount(j), 20, 116 + i * 32, 175);
	// 	i++;
	// }
	// for(u16 j = 0 ; j < m_inventory.nbArmors() ; j++) {
	// 	printItem(m_inventory.getArmor(j), m_inventory.getArmorCount(j), 20, 116 + i * 32, 175);
	// 	i++;
	// }
	// for(u16 j = 0 ; j < m_inventory.nbWeapons() ; j++) {
	// 	printItem(m_inventory.getWeapon(j), m_inventory.getWeaponCount(j), 20, 116 + i * 32, 175);
	// 	i++;
	// }
}

