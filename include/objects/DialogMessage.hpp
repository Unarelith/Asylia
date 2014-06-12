/*
 * =====================================================================================
 *
 *       Filename:  DialogMessage.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/06/2014 09:58:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef DIALOGMESSAGE_HPP_
#define DIALOGMESSAGE_HPP_

class DialogMessage {
	public:
		DialogMessage(std::string str);
		~DialogMessage();
		
		enum Type {
			SimpleMessage,
			Choice,
			BattleStart
		};
		
	private:
		Type m_type;
		
		std::string m_string;
		
		u16 m_scope;
		u16 m_scopePos;
};

#endif // DIALOGMESSAGE_HPP_
