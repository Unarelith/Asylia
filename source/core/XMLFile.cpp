/*
 * =====================================================================================
 *
 *       Filename:  XMLFile.cpp
 *
 *    Description:
 *
 *        Created:  24/05/2014 14:52:48
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Debug.hpp"
#include "XMLFile.hpp"

XMLFile::XMLFile(const char *filename) {
	int code;

	code = m_xml.LoadFile(filename);
	if(code != 0) {
		error("Failed to load %s.", filename);

		switch(code) {
			case tinyxml2::XML_ERROR_FILE_NOT_FOUND:
				error("File not found.");
				break;
			case tinyxml2::XML_ERROR_FILE_COULD_NOT_BE_OPENED:
				error("File couldn't be opened.");
				break;
			case tinyxml2::XML_ERROR_FILE_READ_ERROR:
				error("File read error.");
				break;
			case tinyxml2::XML_ERROR_PARSING_ELEMENT:
				error("Error while parsing element.");
				break;
			case tinyxml2::XML_ERROR_PARSING_ATTRIBUTE:
				error("Error while parsing attribute.");
				break;
			case tinyxml2::XML_ERROR_PARSING_TEXT:
				error("Error while parsing text.");
				break;
			case tinyxml2::XML_ERROR_PARSING_CDATA:
				error("Error while parsing cdata.");
				break;
			case tinyxml2::XML_ERROR_PARSING_COMMENT:
				error("Error while parsing comment.");
				break;
			case tinyxml2::XML_ERROR_PARSING_DECLARATION:
				error("Error while parsing declaration.");
				break;
			case tinyxml2::XML_ERROR_PARSING_UNKNOWN:
				error("Parsing error: Unknown object.");
				break;
			case tinyxml2::XML_ERROR_EMPTY_DOCUMENT:
				error("Empty document.");
				break;
			case tinyxml2::XML_ERROR_MISMATCHED_ELEMENT:
				error("Element mismatched.");
				break;
			case tinyxml2::XML_ERROR_PARSING:
				error("Parsing error.");
				break;
			default:
				error("Unknown error. (CODE: %d)", code);
				break;
		}

		exit(EXIT_FAILURE);
	}

	m_doc.reset(new tinyxml2::XMLHandle(&m_xml));
}

