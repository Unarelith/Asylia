/*
 * =====================================================================================
 *
 *       Filename:  EndActivity.hpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 17:46:04
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ENDACTIVITY_HPP_
#define ENDACTIVITY_HPP_

class EndActivity : public Activity {
	public:
		EndActivity(bool disableCancel = false);
		~EndActivity();

		void update();
		void render();

	private:
		CommandWindow *m_cmdwin;
};

#endif // ENDACTIVITY_HPP_
