/*
 * =====================================================================================
 *
 *       Filename:  TimeManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/03/2014 22:00:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef TIMEMANAGER_HPP_
#define TIMEMANAGER_HPP_

namespace TimeManager {
	void beginMeasuringRenderingTime();
	void pauseMeasuringRenderingTime();
	void resumeMeasuringRenderingTime();
	void endMeasuringRenderingTime();
	
	bool isTimeToUpdate();
	bool hasEnoughTimeToDraw();
	void waitUntilItsTime();
	void measureFrameDuration();
	
	extern u32 renderingTimeMean;
	extern u32 tempBeginRendering;
	extern u32 pause;
	extern u32 frameBegin;
	extern u32 frameEnd;
	extern u32 timeToWait;
	extern std::vector<u32> renderingTimeValues;
};

#endif // TIMEMANAGER_HPP_
