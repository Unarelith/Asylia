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
		
		static std::stack<Activity*> activities;
		static std::stack<Activity*> activitiesBin;
		
		static Activity *top() { return activities.top(); }
		static void pop() { delete top(); activities.pop(); }
		static void push(Activity *activity);
		static int size() { return activities.size(); }
		static void checkActivitiesToDelete() { if(activitiesBin.size() > 0 && activitiesBin.top()) { delete activitiesBin.top(); activitiesBin.pop(); } }
		
		static DialogActivity *newDialog() { DialogActivity *dialog = new DialogActivity(); push(dialog); return dialog; }
		static DialogActivity *newDialogWithParent(Activity *parent) { DialogActivity *dialog = new DialogActivity(parent); push(dialog); return dialog; }
		
		static void startBattle(u16 id) { push(new BattleActivity(BattleManager::battles[id])); }
};

#endif // ACTIVITYMANAGER_HPP_
