/*
 * =====================================================================================
 *
 *       Filename:  EventListener.hpp
 *
 *    Description:
 *
 *        Created:  21/06/2014 19:19:11
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
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
