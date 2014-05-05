/*
 * =====================================================================================
 *
 *       Filename:  Item.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2014 18:01:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

u16 Item::count = 0;

Item::Item(std::string name, std::string description, std::string thumbnail) {
	m_id = count;
	count++;
	
	m_type = Type::BasicItem;
	
	m_name = name;
	m_description = description;
	
	m_level = 1;
	
	m_thumbnail = new Image(thumbnail.c_str());
}

Item::~Item() {
	delete m_thumbnail;
}

