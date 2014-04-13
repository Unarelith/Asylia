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
		EquipItemWindow *m_itemwin;
		EquipStatsWindow *m_statswin;
};

#endif // EQUIPACTIVITY_HPP_
