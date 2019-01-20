/*
 * =====================================================================================
 *
 *       Filename:  ItemActivity.hpp
 *
 *    Description:
 *
 *        Created:  24/03/2014 22:24:46
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
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
