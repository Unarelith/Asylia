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
	
	m_inventory = CharacterManager::player->inventory();
	
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

Battler::Battler(std::string name, std::string appearance, u8 level) {
	m_name = name;
	
	m_image = new Image(appearance.c_str());
	
	m_inventory = CharacterManager::player->inventory();
	
	m_level = level;
	
	m_state = State::Normal;
	
	m_type = Type::TypeNone;
}

void Battler::calculateAllStats(u16 agi, u16 vit, u16 dex, u16 str, u16 wis, u16 intell) {
	m_basehp = 2 * vit + 3 * str + 4 * intell;
	m_basesp = 2 * str + 3 * intell + 4 * wis;
	
	m_hp = m_basehp;
	m_sp = m_basesp;
	
	m_atk = 0.2 * vit + 0.3 * dex + 0.5 * str;
	m_def = 0.2 * intell + 0.3 * vit + 0.5 * agi;
	
	m_agi = agi;
	m_vit = vit;
	m_dex = dex;
	m_str = str;
	m_wis = wis;
	m_int = intell;
}

Battler::~Battler() {
	if(m_image) delete m_image;
}

void Battler::blink() {
	m_image->setColorMod(Color(abs(int(SDL_GetTicks() / 4 % 255 - 128)) + 127, abs(int(SDL_GetTicks() / 4 % 255 - 128)) + 127, abs(int(SDL_GetTicks() / 4 % 255 - 128)) + 127));
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
		m_image->setColorMod(Color(r, 128, 128));
	}
	
	if(a > 20) {
		a -= 20;
		m_image->setAlphaMod(a);
	}
	
	if(a <= 20) {
		m_image->hidden(true);
		a = 255;
		r = 0;
	}
}

