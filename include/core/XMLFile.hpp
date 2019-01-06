/*
 * =====================================================================================
 *
 *       Filename:  XMLFile.hpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  24/05/2014 15:05:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef XMLFILE_HPP_
#define XMLFILE_HPP_

class XMLFile {
	public:
		XMLFile(const char *filename);
		~XMLFile();

		XMLHandle FirstChildElement(const char *element) { return m_doc->FirstChildElement(element); }

	private:
		XMLDocument m_xml;
		XMLHandle *m_doc;
};

#endif // XMLFILE_HPP_
