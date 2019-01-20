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
#include "Asylia.hpp"

XMLFile::XMLFile(const char *filename) {
	int code;

	code = m_xml.LoadFile(filename);
	if(code != 0) {
		error("Failed to load %s.", filename);

		switch(code) {
			case XML_ERROR_FILE_NOT_FOUND:
				error("File not found.");
				break;
			case XML_ERROR_FILE_COULD_NOT_BE_OPENED:
				error("File couldn't be opened.");
				break;
			case XML_ERROR_FILE_READ_ERROR:
				error("File read error.");
				break;
			case XML_ERROR_ELEMENT_MISMATCH:
				error("Element mismatch.");
				break;
			case XML_ERROR_PARSING_ELEMENT:
				error("Error while parsing element.");
				break;
			case XML_ERROR_PARSING_ATTRIBUTE:
				error("Error while parsing attribute.");
				break;
			case XML_ERROR_IDENTIFYING_TAG:
				error("Error while identifying tag.");
				break;
			case XML_ERROR_PARSING_TEXT:
				error("Error while parsing text.");
				break;
			case XML_ERROR_PARSING_CDATA:
				error("Error while parsing cdata.");
				break;
			case XML_ERROR_PARSING_COMMENT:
				error("Error while parsing comment.");
				break;
			case XML_ERROR_PARSING_DECLARATION:
				error("Error while parsing declaration.");
				break;
			case XML_ERROR_PARSING_UNKNOWN:
				error("Parsing error: Unknown object.");
				break;
			case XML_ERROR_EMPTY_DOCUMENT:
				error("Empty document.");
				break;
			case XML_ERROR_MISMATCHED_ELEMENT:
				error("Element mismatched.");
				break;
			case XML_ERROR_PARSING:
				error("Parsing error.");
				break;
			default:
				error("Unknown error. (CODE: %d)", code);
				break;
		}

		exit(EXIT_FAILURE);
	}

	m_doc = new XMLHandle(&m_xml);
}

XMLFile::~XMLFile() {
	delete m_doc;
}

