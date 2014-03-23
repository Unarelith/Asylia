/*
 * =====================================================================================
 *
 *       Filename:  ActivityManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/03/2014 21:49:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

std::stack<Activity*> ActivityManager::activities;

void ActivityManager::init() {
#ifdef __ANDROID__ // FIXME: Tricky solution for issue #7 but not really good
	activities.push(new MapActivity);
	((MapActivity *)activities.top())->init();
	activities.pop();
#endif

#ifdef NO_TITLESCREEN
	activities.push(new MapActivity);
	((MapActivity *)activities.top())->init();
#else
	activities.push(new TitleActivity);
#endif
}

