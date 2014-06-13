/*
 * =====================================================================================
 *
 *       Filename:  TimeManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/03/2014 22:04:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

u32 TimeManager::renderingTimeMean = 0;
u32 TimeManager::tempBeginRendering = 0;
u32 TimeManager::frameBegin = 0;
u32 TimeManager::frameEnd = 0;
u32 TimeManager::timeToWait = 0;
std::vector<u32> TimeManager::renderingTimeValues;
u16 TimeManager::maxFrameskip = 5;
u16 TimeManager::frameskip = 0;
u16 TimeManager::currentFrameDuration = 33;

void TimeManager::beginMeasuringRenderingTime() {
	tempBeginRendering = SDL_GetTicks();
}

void TimeManager::endMeasuringRenderingTime() {
	u32 sum;
	
	renderingTimeValues.push_back(SDL_GetTicks() - tempBeginRendering);
	if(renderingTimeValues.size() > 10) {
		sum = std::accumulate(renderingTimeValues.begin(), renderingTimeValues.end(), 0);
		renderingTimeMean = sum / renderingTimeValues.size();
		//debug("Rendering time mean: %ld", renderingTimeMean);
		renderingTimeValues.clear();
	}
}

bool TimeManager::isTimeToUpdate() {
	frameBegin = SDL_GetTicks();
	if(frameBegin - frameEnd < timeToWait) {
		return false;
	} else {
		timeToWait = 0;
		return true;
	}
}

bool TimeManager::hasEnoughTimeToDraw() {
	if(SDL_GetTicks() - frameBegin + renderingTimeMean > 33) {
		frameskip++;
		if(frameskip > maxFrameskip) {
			frameskip = 0;
			return true;
		} else {
			return false;
		}
	} else {
		return true;
	}
}

void TimeManager::waitUntilItsTime() {
	SDL_Delay(timeToWait - ((SDL_GetTicks() - frameBegin) + (frameBegin - frameEnd)));
}

void TimeManager::measureFrameDuration() {
	if(timeToWait == 0) {
		frameEnd = SDL_GetTicks();
		if(frameEnd - frameBegin <= 33) {
			timeToWait = 33 - (frameEnd - frameBegin);
			currentFrameDuration = 33;
		} else {
			timeToWait = 0;
			currentFrameDuration = frameEnd - frameBegin + 1;
		}
	}
}

void TimeManager::renderRTMCounter() {
	InfoWindow win(GameWindow::main->width() - 120,
				   GameWindow::main->height() - 52,
				   120, 52);
	
	win.drawTextCentered(std::string("RTM: ") + to_string(renderingTimeMean));
}

