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

u8 Item::count = 0;

Item::Item(std::string name, std::string description, u8 level, std::string thumbnail) {
	m_id = count;
	count++;
	
	m_name = name;
	m_description = description;
	
	m_level = level;
	
	m_thumbnail = new Image(thumbnail.c_str());
}

Item::~Item() {
	delete m_thumbnail;
}

