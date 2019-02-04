/*
 * =====================================================================================
 *
 *       Filename:  EquipState.hpp
 *
 *    Description:
 *
 *        Created:  10/04/2014 19:49:33
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef EQUIPSTATE_HPP_
#define EQUIPSTATE_HPP_

#include <memory>

#include "Actor.hpp"
#include "ApplicationState.hpp"
#include "Equipment.hpp"
#include "EquipChoiceWindow.hpp"
#include "EquipStatsWindow.hpp"
#include "ItemWindow.hpp"
#include <gk/core/IntTypes.hpp>

class EquipState : public ApplicationState {
	public:
		EquipState(u8 actorPos, ApplicationState *parent = nullptr);

		void update();
		void render();

		bool itemMode() const { return m_itemMode; }

		u16 choicewinPos() { return m_choicewin->pos(); }

	private:
		bool m_itemMode;

		Actor *m_actor = nullptr;

		Equipment *m_equipment = nullptr;

		std::unique_ptr<EquipStatsWindow> m_statswin;
		std::unique_ptr<EquipChoiceWindow> m_choicewin;

		std::unique_ptr<ItemWindow> m_itemwin;
};

#endif // EQUIPSTATE_HPP_
