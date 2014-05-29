/*
 * =====================================================================================
 *
 *       Filename:  LanguageManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/04/2014 13:49:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef LANGUAGEMANAGER_HPP_
#define LANGUAGEMANAGER_HPP_

class LanguageManager {
	public:
		static void init(std::string language);
		
		static std::string translate(std::string str);
		
		static std::map<std::string, std::string> text;
		static std::string currentLanguage;
};

std::string _t(std::string str);

#endif // LANGUAGEMANAGER_HPP_
