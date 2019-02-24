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
#include "Item.hpp"

Item::Item(const std::string &name, const std::string &description, const std::string &thumbnail) {
	m_id = 0;

	m_type = Type::BasicItem;

	m_effect = Effect::None;

	m_name = name;
	m_description = description;

	m_level = 1;

	m_thumbnail.load(thumbnail);

	m_equipped = false;
}

