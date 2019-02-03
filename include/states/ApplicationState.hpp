/*
 * =====================================================================================
 *
 *       Filename:  ApplicationState.hpp
 *
 *    Description:
 *
 *        Created:  20/03/2014 21:01:10
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef APPLICATIONSTATE_HPP_
#define APPLICATIONSTATE_HPP_

#include "SDLHeaders.hpp"

class ApplicationState {
	public:
		ApplicationState(ApplicationState *parent = nullptr);
		virtual ~ApplicationState() = 0;

		virtual void update() = 0;
		virtual void render() = 0;

		void pollEvents();

		void renderBackground();

		void screenshot(ApplicationState *applicationstate);

		typedef enum {
			None,
			Map,
			Message,
			Menu,
			Lua,
			TitleScreen,
			GameEnd,
			Items,
			Equip,
			BattleAct
		} Type;

		Type type() const { return m_type; }

		ApplicationState *parent() const { return m_parent; }

	protected:
		Type m_type;

		ApplicationState *m_parent;

		SDL_Texture *m_background;
};

#endif // APPLICATIONSTATE_HPP_
