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
		static std::queue<Activity*> activitiesBin;
		
		static Activity *top() { return activities.top(); }
		static void pop() { activitiesBin.push(top()); activities.pop(); }
		static void push(Activity *activity) { activities.push(activity); }
		static int size() { return activities.size(); }
		static void checkActivitiesToDelete() { if(activitiesBin.size() > 0 && activitiesBin.front()) { delete activitiesBin.front(); activitiesBin.pop(); } }
		
		static DialogActivity *newDialog(Activity *parent = NULL) { DialogActivity *dialog = new DialogActivity(parent); activities.push(dialog); return dialog; }
};

#endif // ACTIVITYMANAGER_HPP_
