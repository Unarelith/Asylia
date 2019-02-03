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

#include <map>
#include <string>

class LanguageManager {
	public:
		static void init(const std::string &language);

		static const std::string &translate(const std::string &str);

		static std::map<std::string, std::string> text;
		static std::string currentLanguage;
};

const std::string &_t(const std::string &str);

#endif // LANGUAGEMANAGER_HPP_
