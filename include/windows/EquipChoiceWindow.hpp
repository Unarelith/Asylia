/*
 * =====================================================================================
 *
 *       Filename:  EquipChoiceWindow.hpp
 *
 *    Description:
 *
 *        Created:  17/04/2014 20:38:44
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef EQUIPCHOICEWINDOW_HPP_
#define EQUIPCHOICEWINDOW_HPP_

#include "Equipment.hpp"
#include "SelectableWindow.hpp"

class EquipChoiceWindow : public SelectableWindow {
	public:
		EquipChoiceWindow(Equipment *equipment);

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		Equipment *m_equipment;

		mutable gk::Text m_text{"font-default", 18}; // FIXME
};

#endif // EQUIPCHOICEWINDOW_HPP_
