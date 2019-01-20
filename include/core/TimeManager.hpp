/*
 * =====================================================================================
 *
 *       Filename:  TimeManager.hpp
 *
 *    Description:
 *
 *        Created:  14/03/2014 22:00:01
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TIMEMANAGER_HPP_
#define TIMEMANAGER_HPP_

namespace TimeManager {
	void beginMeasuringRenderingTime();
	void endMeasuringRenderingTime();

	bool isTimeToUpdate();
	bool hasEnoughTimeToDraw();
	void waitUntilItsTime();
	void measureFrameDuration();

	void renderRTMCounter();

	extern u32 renderingTimeMean;
	extern u32 tempBeginRendering;
	extern u32 frameBegin;
	extern u32 frameEnd;
	extern u32 timeToWait;
	extern std::vector<u32> renderingTimeValues;
	extern u16 maxFrameskip;
	extern u16 frameskip;
	extern u16 currentFrameDuration;
};

#endif // TIMEMANAGER_HPP_
