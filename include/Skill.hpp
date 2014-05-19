/*
 * =====================================================================================
 *
 *       Filename:  Skill.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/05/2014 17:55:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef SKILL_HPP_
#define SKILL_HPP_

class Skill : public Item {
	public:
		Skill(std::string name, std::string description, std::string thumbnail, u16 atk, double hitRate);
		~Skill();
		
		u16 atk() const { return m_atk; }
		double hitRate() const { return m_hitRate; }
		
		static u16 count;
		
	private:
		u16 m_atk;
		double m_hitRate;
};

#endif // SKILL_HPP_
