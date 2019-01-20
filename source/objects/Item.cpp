/*
 * =====================================================================================
 *
 *       Filename:  Item.cpp
 *
 *    Description:
 *
 *        Created:  05/04/2014 18:01:13
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Item::Item(std::string name, std::string description, std::string thumbnail, Animation *battleAnimation) {
	m_id = 0;

	m_type = Type::BasicItem;

	m_effect = Effect::None;

	m_name = name;
	m_description = description;

	m_level = 1;

	m_thumbnail = new Image(thumbnail.c_str());

	m_battleAnimation = battleAnimation;

	m_equipped = false;
}

Item::~Item() {
	delete m_thumbnail;
}

