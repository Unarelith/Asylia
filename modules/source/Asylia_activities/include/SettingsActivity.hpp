/*
 * =====================================================================================
 *
 *       Filename:  SettingsActivity.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/05/2014 16:51:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef SETTINGSACTIVITY_HPP_
#define SETTINGSACTIVITY_HPP_

class SettingsActivity : public Activity {
	public:
		SettingsActivity(Activity *parent = NULL);
		~SettingsActivity();
		
		void update();
		void render();
		
		enum Mode {
			Settings,
			Language,
			Sound
		};
		
		void mode(Mode mode) { m_mode = mode; }
		
	private:
		CommandWindow *m_settings;
		CommandWindow *m_sound;
		CommandWindow *m_language;
		
		Mode m_mode;
};

#endif // SETTINGSACTIVITY_HPP_
