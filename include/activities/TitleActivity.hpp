/*
 * =====================================================================================
 *
 *       Filename:  TitleActivity.hpp
 *
 *    Description:
 *
 *        Created:  22/03/2014 17:18:32
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TITLEACTIVITY_HPP_
#define TITLEACTIVITY_HPP_

class TitleActivity : public Activity {
	public:
		TitleActivity();
		~TitleActivity();

		void update();
		void render();

	private:
		Image *m_background;
		CommandWindow *m_cmdwin;
};

#endif // TITLEACTIVITY_HPP_
