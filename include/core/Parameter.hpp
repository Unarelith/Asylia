/*
 * =====================================================================================
 *
 *       Filename:  Parameter.hpp
 *
 *    Description:
 *
 *        Created:  17/06/2014 18:48:33
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef PARAMETER_HPP_
#define PARAMETER_HPP_

#include <string>
#include <memory>
#include <vector>

#include <gk/core/IntTypes.hpp>

class Parameter {
	public:
		Parameter() = default;
		virtual ~Parameter() = default;

		virtual void *value() = 0;

		bool isInteger() { return m_type == Type::IntParameter; }
		bool isBoolean() { return m_type == Type::BoolParameter; }
		bool isFloat() { return m_type == Type::FloatParameter; }
		bool isString() { return m_type == Type::StringParameter; }

		enum Type {
			Undefined,
			IntParameter,
			BoolParameter,
			FloatParameter,
			StringParameter
		};

		Type type() const { return m_type; }

	protected:
		Type m_type = Type::Undefined;
};

class IntParameter : public Parameter {
	public:
		IntParameter(int value);

		void *value() { return (void*)&m_value; }

	private:
		int m_value;
};

class BoolParameter : public Parameter {
	public:
		BoolParameter(bool value);

		void *value() { return (void*)&m_value; }

	private:
		bool m_value;
};

class FloatParameter : public Parameter {
	public:
		FloatParameter(float value);

		void *value() { return (void*)&m_value; }

	private:
		float m_value;
};

class StringParameter : public Parameter {
	public:
		StringParameter(const std::string &value);

		void *value() { return (void*)&m_value; }

	private:
		std::string m_value;
};

class ParameterList {
	public:
		ParameterList() = default;

		void clear() { m_list.clear(); }

		Parameter *at(u16 id) const { return m_list[id].get(); }
		Parameter *operator[](u16 id) const { return m_list[id].get(); }

		u16 size() const { return m_list.size(); }

		void addIntParameter(int param) { m_list.emplace_back(new IntParameter(param)); }
		void addBoolParameter(bool param) { m_list.emplace_back(new BoolParameter(param)); }
		void addFloatParameter(float param) { m_list.emplace_back(new FloatParameter(param)); }
		void addStringParameter(const std::string &param) { m_list.emplace_back(new StringParameter(param)); }

	private:
		std::vector<std::shared_ptr<Parameter>> m_list;
};

#endif // PARAMETER_HPP_
