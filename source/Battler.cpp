/*
 * =====================================================================================
 *
 *       Filename:  Battler.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/04/2014 19:32:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

Battler::Battler(const Battler &battler) {
	m_name = battler.m_name;
	
	m_image = new Image(*battler.m_image);
	
	m_inventory = battler.m_inventory;
	
	m_level = battler.m_level;
	
	m_hp = battler.m_hp;
	m_sp = battler.m_sp;
	
	m_basehp = battler.m_basehp;
	m_basesp = battler.m_basesp;
	
	m_atk = battler.m_atk;
	m_def = battler.m_def;
	
	m_state = battler.m_state;
	
	m_type = battler.m_type;
}

Battler::Battler(std::string name, std::string appearance, u8 level, s16 hp, s16 sp, u16 atk, u16 def) {
	m_name = name;
	
	m_image = new Image(appearance.c_str());
	
	m_inventory = NULL;
	
	m_level = level;
	
	m_hp = hp;
	m_sp = sp;
	
	m_basehp = hp;
	m_basesp = sp;
	
	m_atk = atk;
	m_def = def;
	
	m_state = State::Normal;
	
	m_type = Type::TypeNone;
}

Battler::~Battler() {
	if(m_image) delete m_image;
}

void Battler::blink() {
	m_image->setAlphaMod(abs(int(SDL_GetTicks() / 4 % 255 - 128)) + 127);
}

u16 Battler::totalAtk() {
	u16 atk = m_atk;
	if(m_inventory && m_inventory->weapon()) atk += m_inventory->weapon()->atk();
	return atk;
}

u16 Battler::totalDef() {
	u16 def = m_def;
	if(m_inventory) {
		for(auto it : m_inventory->armorlist()) {
			def += it->def();
		}
	}
	return def;
}

std::string Battler::getStateString() {
	std::string str;
	
	switch(m_state) {
		case State::Normal: str = _t("Normal"); break;
		default: break;
	}
	
	return std::string("[") + str + "]";
}

void Battler::attack(Battler *battler, Skill *skill) {
	battler->hurt(m_atk + skill->atk());
}

u8 r = 0;
u8 a = 255;
void Battler::kill() {
	if(r < 248) {
		r += 7;
		m_image->setColorMod(Color(r, 255, 255));
	}
	
	if(a > 10) {
		a -= 10;
		m_image->setAlphaMod(a);
	}
	
	if(a <= 10) {
		m_image->hidden(true);
		a = 255;
		r = 0;
	}
}

