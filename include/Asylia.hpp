/*
 * =====================================================================================
 *
 *       Filename:  Asylia.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/03/2014 21:41:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef ASYLIA_HPP_
#define ASYLIA_HPP_

#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <numeric>

#include "SDLHeaders.hpp"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;
typedef signed long s32;

#define APP_NAME "Asylia"

#define OVERWORLD_SIZE 1

#define CHARA_SPEED 4

#define COLORED_DEBUG

#ifdef __ANDROID__
	#define VIEWPORT
	#define PAD
	
	#define info(txt...) __android_log_print(ANDROID_LOG_INFO, APP_NAME, txt)
	#define debug(txt...) __android_log_print(ANDROID_LOG_DEBUG, APP_NAME, txt)
	#define warn(txt...) __android_log_print(ANDROID_LOG_WARNING, APP_NAME, txt)
	#define error(txt...) __android_log_print(ANDROID_LOG_ERROR, APP_NAME, txt)
#else
	#ifdef COLORED_DEBUG
		#define info(txt...) { printf("\33[0;36;01m[%s] | INFO:\t", APP_NAME); printf(txt); printf("\33[0m\n"); }
		#define debug(txt...) { printf("\33[0;36;01m[%s] | DEBUG:\t", APP_NAME); printf(txt); printf("\33[0m\n"); }
		#define warn(txt...) { printf("\33[0;35;01m[%s] | WARN:\t", APP_NAME); printf(txt); printf("\33[0m\n"); }
		#define error(txt...) { fprintf(stderr, "\33[0;35;01m[%s] | ERROR:\t", APP_NAME); fprintf(stderr, txt); printf("\33[0m\n"); }
	#else
		#define info(txt...) { printf("[%s] | INFO:\t", APP_NAME); printf(txt); printf("\n"); }
		#define debug(txt...) { printf("[%s] | DEBUG:\t", APP_NAME); printf(txt); printf("\n"); }
		#define warn(txt...) { printf("[%s] | WARN:\t", APP_NAME); printf(txt); printf("\n"); }
		#define error(txt...) { fprintf("[%s] | ERROR:\t", APP_NAME); fprintf(stderr, txt); printf("\n"); }
	#endif
#endif

#include "SDLManager.hpp"
#include "Color.hpp"
#include "Keyboard.hpp"
#include "Game.hpp"
#include "GameWindow.hpp"
#include "TimeManager.hpp"
#include "Activity.hpp"
#include "ActivityManager.hpp"
#include "Image.hpp"

#endif // ASYLIA_HPP_
