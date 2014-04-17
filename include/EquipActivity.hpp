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

class EquipActivity : public MenuActivity {
	public:
		EquipActivity();
		~EquipActivity();
		
		void update();
		void render();
		
	private:
		EquipStatsWindow *m_statswin;
		EquipChoiceWindow *m_choicewin;
		EquipItemWindow *m_itemwin;
		
		bool m_itemMode;
};

#endif // EQUIPACTIVITY_HPP_
