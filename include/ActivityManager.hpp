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

namespace ActivityManager {
	void init();
	
	extern std::stack<Activity*> activities;
};

#endif // ACTIVITYMANAGER_HPP_
