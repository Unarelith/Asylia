/*
 * =====================================================================================
 *
 *       Filename:  Parameter.cpp
 *
 *    Description:
 *
 *        Created:  17/06/2014 22:58:23
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Parameter.hpp"

IntParameter::IntParameter(int value) {
	m_type = Type::IntParameter;

	m_value = value;
}

BoolParameter::BoolParameter(bool value) {
	m_type = Type::BoolParameter;

	m_value = value;
}

FloatParameter::FloatParameter(float value) {
	m_type = Type::FloatParameter;

	m_value = value;
}

StringParameter::StringParameter(const std::string &value) {
	m_type = Type::StringParameter;

	m_value = value;
}

