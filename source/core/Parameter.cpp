/*
 * =====================================================================================
 *
 *       Filename:  Parameter.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  17/06/2014 22:58:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Parameter::Parameter() {
	m_type = Type::Undefined;
}

Parameter::~Parameter() {
}

IntParameter::IntParameter(int value) {
	m_type = Type::IntParameter;

	m_value = value;
}

IntParameter::~IntParameter() {
}

BoolParameter::BoolParameter(bool value) {
	m_type = Type::BoolParameter;

	m_value = value;
}

BoolParameter::~BoolParameter() {
}

FloatParameter::FloatParameter(float value) {
	m_type = Type::FloatParameter;

	m_value = value;
}

FloatParameter::~FloatParameter() {
}

StringParameter::StringParameter(std::string value) {
	m_type = Type::StringParameter;

	m_value = value;
}

StringParameter::~StringParameter() {
}

ParameterList::ParameterList(const ParameterList &list) {
	for(auto it : list.m_list) {
		if(it->isInteger()) addIntParameter(*(int*)it->value());
		if(it->isBoolean()) addBoolParameter(*(bool*)it->value());
		if(it->isFloat()) addFloatParameter(*(float*)it->value());
		if(it->isString()) addStringParameter(*(std::string*)it->value());
	}
}

ParameterList::ParameterList() {
}

ParameterList::~ParameterList() {
	clear();
}

void ParameterList::clear() {
	while(m_list.size() != 0) {
		delete m_list.back();
		m_list.pop_back();
	}
}

