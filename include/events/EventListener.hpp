/*
 * =====================================================================================
 *
 *       Filename:  EventListener.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/06/2014 19:19:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef EVENTLISTENER_HPP_
#define EVENTLISTENER_HPP_

class EventListener {
	public:
		enum Type {
			BattleResult,
			MessageActivityAction
		};
		
		static void addBattleResult(u8 battleResult);
		static void addMessageActivityAction(u8 pos);
		
		static s32 getLastValueOf(Type type);
		
		static s8 lastBattleResult();
		static s8 lastMessageActivityAction();
		
		static std::vector<std::pair<Type, s32>> actionHistory;
};

#endif // EVENTLISTENER_HPP_
