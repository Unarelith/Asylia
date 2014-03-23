/*
 * =====================================================================================
 *
 *       Filename:  Event.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/03/2014 23:50:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef EVENT_HPP_
#define EVENT_HPP_

class Event : public Character {
	public:
		Event(std::string folder, std::string table, std::string appearance, u16 x, u16 y, u8 anim, u16 area, u16 mapX, u16 mapY);
		~Event();
		
		void init();
		
		void update();
		void render();
		
		void action();
		void collisionAction();
		
		std::string table() const { return m_table; }
		
	private:
		std::string m_folder;
		std::string m_table;
};

#endif // EVENT_HPP_
