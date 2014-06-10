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
		EquipActivity(Activity *parent = NULL);
		~EquipActivity();
		
		void update();
		void render();
		
	private:
		EquipStatsWindow m_statswin;
		EquipChoiceWindow m_choicewin;
		ItemWindow *m_itemwin;
		
		bool m_itemMode;
		
		Inventory *m_inventory;
};

#endif // EQUIPACTIVITY_HPP_
