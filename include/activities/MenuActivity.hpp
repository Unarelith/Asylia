/*
 * =====================================================================================
 *
 *       Filename:  MenuActivity.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/03/2014 18:21:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef MENUACTIVITY_HPP_
#define MENUACTIVITY_HPP_

class MenuActivity : public Activity {
	public:
		MenuActivity(Activity *parent = NULL);
		~MenuActivity();
		
		void loadCommandWindow();
		
		void update();
		void render();
		
		CommandWindow *cmdwin() { return m_cmdwin; }
		
		void actorChoiceModeOn() { m_actorChoiceMode = true; }
		
	private:
		CommandWindow *m_cmdwin;
		
		ActorChoiceWindow *m_actorChoicewin;
		
		bool m_actorChoiceMode;
};

#endif // MENUACTIVITY_HPP_
