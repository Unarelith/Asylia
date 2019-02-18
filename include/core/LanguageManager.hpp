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

#include "Singleton.hpp"

class LanguageManager : public Singleton<LanguageManager> {
	public:
		void init(const std::string &language);

		const std::string &translate(const std::string &str);

	private:
		std::map<std::string, std::string> m_text;
		std::string m_currentLanguage;
};

const std::string &_t(const std::string &str);

#endif // LANGUAGEMANAGER_HPP_
