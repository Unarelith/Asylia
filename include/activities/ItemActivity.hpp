/*
 * =====================================================================================
 *
 *       Filename:  ItemActivity.hpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  24/03/2014 22:24:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef ITEMACTIVITY_HPP_
#define ITEMACTIVITY_HPP_

class ItemActivity : public Activity {
	public:
		ItemActivity(Activity *parent = NULL);
		~ItemActivity();

		void update();
		void render();

	private:
		ItemWindow *m_itemwin;
};

#endif // ITEMACTIVITY_HPP_
