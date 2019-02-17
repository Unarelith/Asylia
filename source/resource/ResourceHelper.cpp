/*
 * =====================================================================================
 *
 *       Filename:  ResourceHelper.cpp
 *
 *    Description:
 *
 *        Created:  17/02/2019 21:24:12
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/resource/ResourceHandler.hpp>

#include "Actor.hpp"
#include "Animation.hpp"
#include "Armor.hpp"
#include "Enemy.hpp"
#include "Item.hpp"
#include "ResourceHelper.hpp"
#include "Skill.hpp"
#include "Troop.hpp"
#include "Weapon.hpp"

SpriteAnimation &ResourceHelper::getAnimation(const std::string &name, size_t id) {
	return gk::ResourceHandler::getInstance().get<std::vector<SpriteAnimation>>("spriteanim-" + name)[id];
}

Animation *ResourceHelper::getAnimationByName(const std::string &name) {
	return &gk::ResourceHandler::getInstance().get<Animation>("animation-" + name);
}

Item *ResourceHelper::getItem(u16 id) {
	return &gk::ResourceHandler::getInstance().get<Item>("item-" + std::to_string(id));
}

Armor *ResourceHelper::getArmor(u16 id) {
	return &gk::ResourceHandler::getInstance().get<Armor>("armor-" + std::to_string(id));
}

Weapon *ResourceHelper::getWeapon(u16 id) {
	return &gk::ResourceHandler::getInstance().get<Weapon>("weapon-" + std::to_string(id));
}

Skill *ResourceHelper::getSkill(u16 id) {
	return &gk::ResourceHandler::getInstance().get<Skill>("skill-" + std::to_string(id));
}

Actor *ResourceHelper::getActor(u16 id) {
	return &gk::ResourceHandler::getInstance().get<Actor>("actor-" + std::to_string(id));
}

Enemy *ResourceHelper::getEnemy(u16 id) {
	return &gk::ResourceHandler::getInstance().get<Enemy>("enemy-" + std::to_string(id));
}

Troop *ResourceHelper::getTroop(u16 id) {
	return &gk::ResourceHandler::getInstance().get<Troop>("troop-" + std::to_string(id));
}

