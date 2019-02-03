/*
 * =====================================================================================
 *
 *       Filename:  XMLFile.hpp
 *
 *    Description:
 *
 *        Created:  24/05/2014 15:05:35
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef XMLFILE_HPP_
#define XMLFILE_HPP_

#include <tinyxml2.h>

#include <memory>

class XMLFile {
	public:
		XMLFile(const char *filename);

		tinyxml2::XMLHandle FirstChildElement(const char *element) { return m_doc->FirstChildElement(element); }

	private:
		tinyxml2::XMLDocument m_xml;
		std::unique_ptr<tinyxml2::XMLHandle> m_doc;
};

#endif // XMLFILE_HPP_
