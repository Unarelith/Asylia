/*
 * =====================================================================================
 *
 *       Filename:  Battler.cpp
 *
 *    Description:
 *
 *        Created:  22/04/2014 19:32:30
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Battler.hpp"
#include "Character.hpp"
#include "ResourceHelper.hpp"

Battler::Battler(const Battler &battler) {
	m_name = battler.m_name;

	m_image = new Image(*battler.m_image);

	m_sprite = new Sprite(*battler.m_sprite);

	m_level = battler.m_level;
	m_exp = battler.m_exp;

	m_hp = battler.m_hp;
	m_sp = battler.m_sp;

	m_basehp = battler.m_basehp;
	m_basesp = battler.m_basesp;

	m_atk = battler.m_atk;
	m_def = battler.m_def;

	m_agi = battler.m_agi;
	m_vit = battler.m_vit;
	m_dex = battler.m_dex;
	m_str = battler.m_str;
	m_wis = battler.m_wis;
	m_int = battler.m_int;

	m_state = battler.m_state;

	m_type = battler.m_type;
}

Battler::Battler(const std::string &name, const std::string &appearance, u8 level) {
	m_name = name;

	m_image = new Image(appearance.c_str());

	std::string str = appearance;
	m_sprite = new Sprite(str.replace(str.find("battlers"), 8, "characters").c_str(), 32, 48);
	m_sprite->addAnimation(ResourceHelper::getAnimation("Character", DIR_DOWN));
	m_sprite->addAnimation(ResourceHelper::getAnimation("Character", DIR_LEFT));
	m_sprite->addAnimation(ResourceHelper::getAnimation("Character", DIR_RIGHT));
	m_sprite->addAnimation(ResourceHelper::getAnimation("Character", DIR_UP));

	m_level = level;
	m_exp = 0;

	m_state = State::Normal;

	m_type = Type::TypeNone;
}

Battler::~Battler() {
	delete m_sprite;

	delete m_image;
}

void Battler::calculateAllStats(u16 agi, u16 vit, u16 dex, u16 str, u16 wis, u16 intell) {
	m_agi = growAgi(agi, m_level - 1);
	m_vit = growVit(vit, m_level - 1);
	m_dex = growDex(dex, m_level - 1);
	m_str = growStr(str, m_level - 1);
	m_wis = growWis(wis, m_level - 1);
	m_int = growInt(intell, m_level - 1);

	m_basehp = 2 * m_str + 3 * m_vit + 4 * m_wis;
	m_basesp = 2 * m_dex + 3 * m_wis + 4 * m_int;

	m_hp = m_basehp;
	m_sp = m_basesp;

	m_atk = 0.2 * m_vit + 0.3 * m_dex + 0.5 * m_str;
	m_def = 0.2 * m_int + 0.3 * m_vit + 0.5 * m_agi;
}

void Battler::blink() {
	m_image->setColorMod(Color(abs(int(SDL_GetTicks() / 4 % 255 - 128)) + 127, abs(int(SDL_GetTicks() / 4 % 255 - 128)) + 127, abs(int(SDL_GetTicks() / 4 % 255 - 128)) + 127));
	m_image->setAlphaMod(abs(int(SDL_GetTicks() / 4 % 255 - 128)) + 127);
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

void Battler::levelUp() {
	m_exp = abs(expRemainingToLevelUp());

	m_level++;

	m_agi = growAgi(m_agi, 1);
	m_vit = growVit(m_vit, 1);
	m_dex = growDex(m_dex, 1);
	m_str = growStr(m_str, 1);
	m_wis = growWis(m_wis, 1);
	m_int = growInt(m_int, 1);

	m_basehp = 2 * m_str + 3 * m_vit + 4 * m_wis;
	m_basesp = 2 * m_dex + 3 * m_wis + 4 * m_int;

	m_hp = m_basehp;
	m_sp = m_basesp;

	m_atk = 0.2 * m_vit + 0.3 * m_dex + 0.5 * m_str;
	m_def = 0.2 * m_int + 0.3 * m_vit + 0.5 * m_agi;
}

