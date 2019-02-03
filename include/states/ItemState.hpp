/*
 * =====================================================================================
 *
 *       Filename:  ItemState.hpp
 *
 *    Description:
 *
 *        Created:  24/03/2014 22:24:46
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ITEMSTATE_HPP_
#define ITEMSTATE_HPP_

#include <memory>

#include "ApplicationState.hpp"
#include "ItemWindow.hpp"

class ItemState : public ApplicationState {
	public:
		ItemState(ApplicationState *parent = nullptr);

		void update();
		void render();

	private:
		std::unique_ptr<ItemWindow> m_itemwin;
};

#endif // ITEMSTATE_HPP_
