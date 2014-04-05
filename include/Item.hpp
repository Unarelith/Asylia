/*
 * =====================================================================================
 *
 *       Filename:  Item.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2014 17:56:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef ITEM_HPP_
#define ITEM_HPP_

class Item {
	public:
		Item(std::string name, std::string description, u8 level, std::string thumbnail);
		~Item();
		
		std::string name() const { return _t(m_name); }
		std::string description() const { return _t(m_description); }
		
		Image *thumbnail() const { return m_thumbnail; }
		
		static u8 count;
		
	protected:
		u8 m_id;
		
		std::string m_name;
		std::string m_description;
		
		u8 m_level;
		
		Image *m_thumbnail;
};

#endif // ITEM_HPP_
