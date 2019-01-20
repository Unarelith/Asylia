/*
 * =====================================================================================
 *
 *       Filename:  ItemActivity.cpp
 *
 *    Description:
 *
 *        Created:  24/03/2014 22:26:14
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

ItemActivity::ItemActivity(Activity *parent) : Activity(parent) {
	m_type = Type::Items;

	m_itemwin = new ItemWindow(150, 52, GameWindow::main->width() - 150, GameWindow::main->height() - 52, CharacterManager::player->inventory(), 150, 0);
}

ItemActivity::~ItemActivity() {
	delete m_itemwin;
}

void ItemActivity::update() {
	m_itemwin->update();

	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		Sound::Effect::play(Sound::Effect::confirm);
	}

	if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
		Sound::Effect::play(Sound::Effect::back);
		ActivityManager::pop();
	}
}

void ItemActivity::render() {
	renderBackground();

	m_itemwin->draw();
}

