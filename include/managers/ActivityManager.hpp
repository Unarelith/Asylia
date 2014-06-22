/*
 * =====================================================================================
 *
 *       Filename:  ActivityManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/03/2014 21:15:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef ACTIVITYMANAGER_HPP_
#define ACTIVITYMANAGER_HPP_

class ActivityManager {
	public:
		static void init();
		static void free();
		
		static std::stack<Activity*> activities;
		
		static Activity *top() { return activities.top(); }
		static void pop() { delete top(); activities.pop(); }
		static void push(Activity *activity);
		static int size() { return activities.size(); }
		
		static MessageActivity *drawMessage(std::string message) { top()->render(); MessageActivity *activity = new MessageActivity(message); push(activity); return activity; }
		
		static BattleActivity *startBattle(u16 id, bool allowDefeat) { BattleActivity *activity = new BattleActivity(TroopManager::troops[id], allowDefeat); push(activity); return activity; }
};

#endif // ACTIVITYMANAGER_HPP_
