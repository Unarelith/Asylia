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
		Event(std::string name, std::string appearance, u16 x, u16 y, u8 anim, bool solid = false, u16 frameWidth = 32, u16 frameHeight = 48);
		~Event();
		
		void init();
		
		void move(std::string function);
		
		void update();
		void render();
		
		void addAction(std::string luaFunction);
		void processAction();
		bool isProcessingAction() const { return m_processingAction; }
		void waitForNextAction();
		void checkCondition(bool condition);
		
		std::string name() const { return m_name; }
		
	private:
		std::string m_folder;
		std::string m_name;
		
		bool m_processingAction;
		u16 m_actionID;
		std::vector<std::string> m_actions;
};

#endif // EVENT_HPP_
