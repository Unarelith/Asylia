/*
 * =====================================================================================
 *
 *       Filename:  Keyboard.hpp
 *
 *    Description:
 *
 *        Created:  20/03/2014 21:43:44
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef KEYBOARD_HPP_
#define KEYBOARD_HPP_

#include "SDLHeaders.hpp"
#include "Types.hpp"

typedef enum {
	PAD_UP,
	PAD_DOWN,
	PAD_LEFT,
	PAD_RIGHT,
	PAD_A,
	PAD_B,
	PAD_MENU
} PadState;

class Keyboard {
	public:
		static const u8 *getState();

		static void update();

		static void forceUpdate();

		static void resetPad(SDL_Event *e, bool released = false);

		static void updatePad(SDL_Event *e);

		static bool isKeyPressed(u32 key);
		static bool isKeyPressedOnce(u32 key);
		static bool isKeyPressedWithDelay(u32 key, u16 delay);

		static const u8 *state;

		static u8 padState[7];
		static s32 padFinger[7];

		static u32 lastTimePressed[7];

		static u8 pressed[7];

		static u32 keysCode[7];

		static const u32 GameUp;
		static const u32 GameDown;
		static const u32 GameLeft;
		static const u32 GameRight;
		static const u32 GameAttack;
		static const u32 GameBack;
		static const u32 GameMenu;
};

#endif // KEYBOARD_HPP_
