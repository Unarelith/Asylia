/*
 * =====================================================================================
 *
 *       Filename:  Debug.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/03/2014 17:34:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef DEBUG_HPP_
#define DEBUG_HPP_

#ifdef __ANDROID__
	#include <android/log.h>
#endif

#ifdef __ANDROID__
	#define VIEWPORT
	#define PAD
	
	#define info(txt...) __android_log_print(ANDROID_LOG_INFO, APP_NAME, txt)
	#define debug(txt...) __android_log_print(ANDROID_LOG_DEBUG, APP_NAME, txt)
	#define warning(txt...) __android_log_print(ANDROID_LOG_WARN, APP_NAME, txt)
	#define error(txt...) __android_log_print(ANDROID_LOG_ERROR, APP_NAME, txt)
#else
	#ifdef COLORED_DEBUG
		#define info(txt...) { printf("\33[0;36;01m[%s] | INFO:\t", APP_NAME); printf(txt); printf("\33[0m\n"); }
		#define debug(txt...) { printf("\33[0;36;01m[%s] | DEBUG:\t", APP_NAME); printf(txt); printf("\33[0m\n"); }
		#define warning(txt...) { printf("\33[0;35;01m[%s] | WARN:\t", APP_NAME); printf(txt); printf("\33[0m\n"); }
		#define error(txt...) { fprintf(stderr, "\33[0;35;01m[%s] | ERROR:\t", APP_NAME); fprintf(stderr, txt); printf("\33[0m\n"); }
	#else
		#define info(txt...) { printf("[%s] | INFO:\t", APP_NAME); printf(txt); printf("\n"); }
		#define debug(txt...) { printf("[%s] | DEBUG:\t", APP_NAME); printf(txt); printf("\n"); }
		#define warning(txt...) { printf("[%s] | WARN:\t", APP_NAME); printf(txt); printf("\n"); }
		#define error(txt...) { fprintf("[%s] | ERROR:\t", APP_NAME); fprintf(stderr, txt); printf("\n"); }
	#endif
#endif

#endif // DEBUG_HPP_
