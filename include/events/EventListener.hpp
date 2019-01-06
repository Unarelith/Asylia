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

namespace EventListener {
	enum Type {
		MessageActivityAction,
		BattleResult
	};

	void addMessageActivityAction(u8 pos);
	void addBattleResult(u8 battleResult);

	s32 getLastValueOf(Type type);

	s8 lastMessageActivityAction();
	s8 lastBattleResult();

	extern std::vector<std::pair<Type, s32>> actionHistory;
};

#endif // EVENTLISTENER_HPP_
