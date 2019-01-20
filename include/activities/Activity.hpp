/*
 * =====================================================================================
 *
 *       Filename:  Activity.hpp
 *
 *    Description:
 *
 *        Created:  20/03/2014 21:01:10
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ACTIVITY_HPP_
#define ACTIVITY_HPP_

class Activity {
	public:
		Activity(Activity *parent = NULL);
		virtual ~Activity() = 0;

		virtual void update() = 0;
		virtual void render() = 0;

		void pollEvents();

		void renderBackground();

		void screenshot(Activity *activity);

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

		Activity *parent() const { return m_parent; }

	protected:
		Type m_type;

		Activity *m_parent;

		SDL_Texture *m_background;
};

#endif // ACTIVITY_HPP_
