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

class Event{
	public:
		Event(std::string filename, std::string table, u16 x, u16 y, u8 anim, u16 area, u16 mapX, u16 mapY);
		~Event();
		
		void update();
		void render();
		
	private:
		std::string m_table;
};

#endif // EVENT_HPP_
