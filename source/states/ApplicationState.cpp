/*
 * =====================================================================================
 *
 *       Filename:  ApplicationState.cpp
 *
 *    Description:
 *
 *        Created:  20/03/2014 21:21:01
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "ApplicationState.hpp"
#include "EndState.hpp"
#include "GameWindow.hpp"
#include "Game.hpp"
#include "Keyboard.hpp"
#include "MenuState.hpp"
#include "ApplicationStateStack.hpp"

ApplicationState::ApplicationState(ApplicationState *parent) : gk::ApplicationState(parent) {
	m_type = Type::None;

	m_parent = parent;
}

