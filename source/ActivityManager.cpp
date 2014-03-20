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
	activities.push(new GameActivity);
}

