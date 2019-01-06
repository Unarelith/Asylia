/*
 * =====================================================================================
 *
 *       Filename:  EquipActivity.hpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/04/2014 19:49:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef EQUIPACTIVITY_HPP_
#define EQUIPACTIVITY_HPP_

class EquipActivity : public Activity {
	public:
		EquipActivity(u8 actorPos, Activity *parent = NULL);
		~EquipActivity();

		void update();
		void render();

		bool itemMode() const { return m_itemMode; }

		u16 choicewinPos() { return m_choicewin->pos(); }

	private:
		bool m_itemMode;

		Actor *m_actor;

		Equipment *m_equipment;

		EquipStatsWindow *m_statswin;
		EquipChoiceWindow *m_choicewin;

		ItemWindow *m_itemwin;
};

#endif // EQUIPACTIVITY_HPP_
