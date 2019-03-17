/*
 * =====================================================================================
 *
 *       Filename:  Player.cpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 19:49:35
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/input/GamePad.hpp>

#include "Config.hpp"
#include "GameKey.hpp"
#include "Player.hpp"
#include "ResourceHelper.hpp"

Player::Player(const std::string &filename, s16 x, s16 y, u8 direction) : Character(filename.c_str(), x, y, direction) {
	m_type = Type::Player;

	m_speed = CHARA_SPEED;

	addAnimation(ResourceHelper::getAnimation("Character", DIR_DOWN));
	addAnimation(ResourceHelper::getAnimation("Character", DIR_LEFT));
	addAnimation(ResourceHelper::getAnimation("Character", DIR_RIGHT));
	addAnimation(ResourceHelper::getAnimation("Character", DIR_UP));

	m_inventory.addItem(0, 1);
	m_inventory.addItem(1, 1);
	m_inventory.addItem(5, 1);
	m_inventory.addItem(2, 1);
	m_inventory.addItem(3, 1);
	m_inventory.addItem(4, 1);
	m_inventory.addItem(6, 1);

	m_inventory.addWeapon(0, 1);
	m_inventory.addWeapon(1, 1);
	m_inventory.addWeapon(2, 1);
	m_inventory.addWeapon(3, 1);

	m_inventory.addArmor(0, 1);
	m_inventory.addArmor(1, 1);
	m_inventory.addArmor(2, 1);
	m_inventory.addArmor(3, 1);
	m_inventory.addArmor(4, 1);

	m_quests.push_back(ResourceHelper::getQuest(0));
}

void Player::move() {
	if(m_vxCount == 0 && m_vyCount == 0) {
		m_moving = false;

		if(gk::GamePad::isKeyPressed(GameKey::Up)) {
			if(!gk::GamePad::isKeyPressed(GameKey::Down)) {
				m_vy = -m_speed;
				m_moving = true;
			}
		}
		else if(gk::GamePad::isKeyPressed(GameKey::Down)) {
			if(!gk::GamePad::isKeyPressed(GameKey::Up)) {
				m_vy = m_speed;
				m_moving = true;
			}
		}
		else if(gk::GamePad::isKeyPressed(GameKey::Left)) {
			if(!gk::GamePad::isKeyPressed(GameKey::Right)) {
				m_vx = -m_speed;
				m_moving = true;
			}
		}
		else if(gk::GamePad::isKeyPressed(GameKey::Right)) {
			if(!gk::GamePad::isKeyPressed(GameKey::Left)) {
				m_vx = m_speed;
				m_moving = true;
			}
		}
	}

	if(m_vx > 0) m_direction = DIR_RIGHT;
	if(m_vx < 0) m_direction = DIR_LEFT;
	if(m_vy > 0) m_direction = DIR_DOWN;
	if(m_vy < 0) m_direction = DIR_UP;

	testCollisions();

	m_vxCount += abs(m_vx);
	m_vyCount += abs(m_vy);

	gk::Sprite::move(m_vx, m_vy);

	if(m_vxCount >= 32 || m_vyCount >= 32) {
		m_vxCount = 0;
		m_vyCount = 0;

		m_moving = false;

		m_vx = 0;
		m_vy = 0;
	}
}

void Player::addTeamMember(u16 id) {
	m_team.push_back(ResourceHelper::getActor(id));

	if(m_team.size() == 1)
		load(m_team.back()->sprite());
}

