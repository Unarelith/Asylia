/*
 * =====================================================================================
 *
 *       Filename:  LanguageManager.hpp
 *
 *    Description:
 *
 *        Created:  02/04/2014 13:49:13
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
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
