/*
 * =====================================================================================
 *
 *       Filename:  Activity.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/03/2014 21:01:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef ACTIVITY_HPP_
#define ACTIVITY_HPP_

class Activity {
	public:
		Activity();
		~Activity();
		
		virtual void update() = 0;
		virtual void render() = 0;
		
		void pollEvents(bool *quit = NULL);
		
		typedef enum {
			None,
			Map,
			Dialog,
			Menu,
			Lua,
			TitleScreen,
			GameEnd
		} Type;
		
		Type type() const { return m_type; }
		
	protected:
		Type m_type;
};

#endif // ACTIVITY_HPP_
