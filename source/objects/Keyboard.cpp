/*
 * =====================================================================================
 *
 *       Filename:  Keyboard.cpp
 *
 *    Description:
 *
 *        Created:  20/03/2014 21:46:54
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "GameWindow.hpp"
#include "Interface.hpp"
#include "Keyboard.hpp"

const u8 *Keyboard::state = nullptr;
u32 Keyboard::lastTimePressed[7] = {0, 0, 0, 0, 0, 0, 0};
u8 Keyboard::pressed[7] = {0, 0, 0, 0, 0, 0, 0};

const u32 Keyboard::GameUp = PAD_UP;
const u32 Keyboard::GameDown = PAD_DOWN;
const u32 Keyboard::GameLeft = PAD_LEFT;
const u32 Keyboard::GameRight = PAD_RIGHT;
const u32 Keyboard::GameAttack = PAD_A;
const u32 Keyboard::GameBack = PAD_B;
const u32 Keyboard::GameMenu = PAD_MENU;

u32 Keyboard::keysCode[7] = {
	SDL_SCANCODE_UP,
	SDL_SCANCODE_DOWN,
	SDL_SCANCODE_LEFT,
	SDL_SCANCODE_RIGHT,
	SDL_SCANCODE_RETURN,
	SDL_SCANCODE_BACKSPACE,
	SDL_SCANCODE_ESCAPE
};

const u8 *Keyboard::getState() {
	return SDL_GetKeyboardState(nullptr);
}

bool Keyboard::isKeyPressed(u32 key) {
	if(state[keysCode[key]]) {
		return true;
	} else {
		return false;
	}
}

bool Keyboard::isKeyPressedOnce(u32 key) {
	if(state[keysCode[key]]) {
		if(!pressed[key]) {
			pressed[key] = 1;
			return true;
		} else {
			return false;
		}
	} else {
		pressed[key] = 0;
		return false;
	}
}

bool Keyboard::isKeyPressedWithDelay(u32 key, u16 delay) {
	if(state[keysCode[key]] && SDL_GetTicks() - lastTimePressed[key] > delay) {
		lastTimePressed[key] = SDL_GetTicks();
		return true;
	} else {
		if(!state[keysCode[key]]) {
			lastTimePressed[key] = 0;
		}
		return false;
	}
}

void Keyboard::update() {
	state = getState();
}

void Keyboard::forceUpdate() {
	SDL_PumpEvents();
	update();
}

