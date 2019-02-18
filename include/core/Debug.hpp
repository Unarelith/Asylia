/*
 * =====================================================================================
 *
 *       Filename:  Debug.hpp
 *
 *    Description:
 *
 *        Created:  21/03/2014 17:34:50
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef DEBUG_HPP_
#define DEBUG_HPP_

#include <cstdio>

#include <gk/core/SDLHeaders.hpp>

#include "Config.hpp"

#ifdef COLORED_DEBUG
	#define info(txt...) { printf("\33[0;36;01m[%s: %d]\t\t| INFO:\t", APP_NAME, SDL_GetTicks()); printf(txt); printf("\33[0m\n"); }
	#define debug(txt...) { printf("\33[0;36;01m[%s: %d]\t\t| DEBUG:\t", APP_NAME, SDL_GetTicks()); printf(txt); printf("\33[0m\n"); }
	#define warning(txt...) { printf("\33[0;35;01m[%s: %d]\t\t| WARN:\t", APP_NAME, SDL_GetTicks()); printf(txt); printf("\33[0m\n"); }
	#define error(txt...) { fprintf(stderr, "\33[0;35;01m[%s: %d]\t\t| ERROR:\t", APP_NAME, SDL_GetTicks()); fprintf(stderr, txt); printf("\33[0m\n"); }
#else
	#define info(txt...) { printf("[%s: %d]\t\t| INFO:\t", APP_NAME, SDL_GetTicks()); printf(txt); printf("\n"); }
	#define debug(txt...) { printf("[%s: %d]\t\t| DEBUG:\t", APP_NAME, SDL_GetTicks()); printf(txt); printf("\n"); }
	#define warning(txt...) { printf("[%s: %d]\t\t| WARN:\t", APP_NAME, SDL_GetTicks()); printf(txt); printf("\n"); }
	#define error(txt...) { fprintf("[%s: %d]\t\t| ERROR:\t", APP_NAME, SDL_GetTicks()); fprintf(stderr, txt); printf("\n"); }
#endif

#define TRACE(s) { info("Function called: " #s); s }

#endif // DEBUG_HPP_
