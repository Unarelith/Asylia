/*
 * =====================================================================================
 *
 *       Filename:  MapActivity.hpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  21/03/2014 18:19:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
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
