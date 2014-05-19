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
		Item(std::string name, std::string description, std::string thumbnail);
		~Item();
		
		std::string name() const { return _t(m_name); }
		std::string description() const { return _t(m_description); }
		
		u8 level() const { return m_level; }
		
		Image *thumbnail() const { return m_thumbnail; }
		
		static u16 count;
		
		enum Type {
			BasicItem,
			Armor,
			Weapon,
			Skill
		};
		
		Type type() const { return m_type; }
		
	protected:
		u16 m_id;
		
		Type m_type;
		
		std::string m_name;
		std::string m_description;
		
		u8 m_level;
		
		Image *m_thumbnail;
};

#endif // ITEM_HPP_
