/*
 * =====================================================================================
 *
 *       Filename:  Keyboard.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/03/2014 21:46:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

const u8 *Keyboard::state = NULL;
u8 Keyboard::padState[7] = {0, 0, 0, 0, 0, 0, 0};
s32 Keyboard::padFinger[7] = {-1, -1, -1, -1, -1, -1, -1};
u32 Keyboard::lastTimePressed[7] = {0, 0, 0, 0, 0, 0, 0};

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
	return SDL_GetKeyboardState(NULL);
}

bool Keyboard::isKeyPressed(u32 key) {
#ifndef __ANDROID__
	if(state[keysCode[key]]) return true;
	else		   return false;
#else
	if(padState[key]) return true;
	else			  return false;
#endif
}

bool Keyboard::isKeyPressedWithDelay(u32 key, u16 delay) {
#ifndef __ANDROID__
	if(state[keysCode[key]] && SDL_GetTicks() - lastTimePressed[key] > delay) {
		lastTimePressed[key] = SDL_GetTicks();
		return true;
	} else {
		if(!state[keysCode[key]]) {
			lastTimePressed[key] = 0;
		}
		return false;
	}
#else
	if(padState[key] && SDL_GetTicks() - lastTimePressed[key] > delay) {
		lastTimePressed[key] = SDL_GetTicks();
		return true;
	} else {
		if(!padState[key] {
			lastTimePressed[key] = 0;
		}
		return false;
	}
#endif
}

void Keyboard::update() {
	state = getState();
}

void Keyboard::forceUpdate() {
	SDL_PumpEvents();
	update();
}

void Keyboard::resetPad(SDL_Event *e, bool released) {
	// Reset pad state
	if(padFinger[PAD_UP] == e->tfinger.fingerId || padFinger[PAD_UP] < 0) {
		padState[PAD_UP] = 0;
		padState[PAD_DOWN] = 0;
		padState[PAD_LEFT] = 0;
		padState[PAD_RIGHT] = 0;
	}
	if(padFinger[PAD_A] == e->tfinger.fingerId || padFinger[PAD_A] < 0) padState[PAD_A] = 0;
	if(padFinger[PAD_B] == e->tfinger.fingerId || padFinger[PAD_B] < 0) padState[PAD_B] = 0;
	if(padFinger[PAD_MENU] == e->tfinger.fingerId || padFinger[PAD_MENU] < 0) padState[PAD_MENU] = 0;
	
	// Reset finger state
	if(padFinger[PAD_UP] == e->tfinger.fingerId && released) padFinger[PAD_UP] = -1;
	if(padFinger[PAD_A]	== e->tfinger.fingerId && released) padFinger[PAD_A] = -1;
	if(padFinger[PAD_B]	== e->tfinger.fingerId && released) padFinger[PAD_B] = -1;
	if(padFinger[PAD_MENU] == e->tfinger.fingerId && released) padFinger[PAD_MENU] = -1;
}

void Keyboard::updatePad(SDL_Event *e) {
/*	u16 fx = e->tfinger.x * Window::main->viewportW();
	u16 fy = e->tfinger.y * Window::main->viewportH();
	
	u16 px = Interface::pad->posRect().x - Window::main->viewportX();
	u16 py = Interface::pad->posRect().y - Window::main->viewportY();
	
	u16 ax = Interface::buttonA->posRect().x - Window::main->viewportX();
	u16 ay = Interface::buttonA->posRect().y - Window::main->viewportY();
	
	u16 bx = Interface::buttonB->posRect().x - Window::main->viewportX();
	u16 by = Interface::buttonB->posRect().y - Window::main->viewportY();
	
	u16 menux = Interface::buttonMenu->posRect().x - Window::main->viewportX();
	u16 menuy = Interface::buttonMenu->posRect().y - Window::main->viewportY();
	
	resetPad(e);
	
	// Up: (0;0;71;28)
	if(fx > px - 16 && fx < px + 71 + 16 && fy > py - 16 && fy < py + 28 - 8) {
		padState[PAD_UP] = 1;
		padFinger[PAD_UP] = e->tfinger.fingerId;
	}
	
	// Down: (0;44;71;71)
	if(fx > px - 16 && fx < px + 71 + 16 && fy > py + 44 + 8 && fy < py + 71 + 16) {
		padState[PAD_DOWN] = 1;
		padFinger[PAD_UP] = e->tfinger.fingerId;
	}
	
	// Left: (0;0;28;71)
	if(fx > px - 16 && fx < px + 28 - 8 && fy > py - 16 && fy < py + 71 + 16) {
		padState[PAD_LEFT] = 1;
		padFinger[PAD_UP] = e->tfinger.fingerId;
	}
	
	// Right: (44;0;71;71)
	if(fx > px + 44 + 8 && fx < px + 71 + 16 && fy > py - 16 && fy < py + 71 + 16) {
		padState[PAD_RIGHT] = 1;
		padFinger[PAD_UP] = e->tfinger.fingerId;
	}
	
	if(fx > ax && fx < ax + 32 && fy > ay && fy < ay + 32) {
		padState[PAD_A] = 1;
		padFinger[PAD_A] = e->tfinger.fingerId;
	}
	
	if(fx > bx && fx < bx + 32 && fy > by && fy < by + 32) {
		padState[PAD_B] = 1;
		padFinger[PAD_B] = e->tfinger.fingerId;
	}
	
	if(fx > menux && fx < menux + 32 && fy > menuy && fy < menuy + 32) {
		padState[PAD_MENU] = 1;
		padFinger[PAD_MENU] = e->tfinger.fingerId;
	}*/
}

