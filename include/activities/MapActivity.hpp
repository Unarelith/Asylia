/*
 * =====================================================================================
 *
 *       Filename:  MapActivity.hpp
 *
 *    Description:
 *
 *        Created:  21/03/2014 18:19:43
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MAPACTIVITY_HPP_
#define MAPACTIVITY_HPP_

class MapActivity : public Activity {
	public:
		MapActivity();
		~MapActivity();

		void init();

		void update();
		void render();
};

#endif // MAPACTIVITY_HPP_
