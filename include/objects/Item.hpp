/*
 * =====================================================================================
 *
 *       Filename:  Item.hpp
 *
 *    Description:
 *
 *        Created:  05/04/2014 17:56:33
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ITEM_HPP_
#define ITEM_HPP_

class Item {
	public:
		Item(std::string name, std::string description, std::string thumbnail, Animation *battleAnimation = NULL);
		~Item();

		u16 id() const { return m_id; }

		std::string name() const { return _t(m_name); }
		std::string description() const { return _t(m_description); }

		u8 level() const { return m_level; }

		Image *thumbnail() const { return m_thumbnail; }

		enum Type {
			BasicItem,
			Armor,
			Weapon,
			Skill
		};

		enum Effect {
			None,
			StatsEffect,
			MapEffect
		};

		Type type() const { return m_type; }

		Effect effect() const { return m_effect; }

		Animation *battleAnimation() const { return m_battleAnimation; }

		bool equipped() const { return m_equipped; }

		void setID(u16 id) { m_id = id; }

		void setEffect(int effect) { m_effect = (Item::Effect)effect; }

		void setEquipped(bool equipped) { m_equipped = equipped; }

	protected:
		u16 m_id;

		Type m_type;

		Effect m_effect;

		std::string m_name;
		std::string m_description;

		u8 m_level;

		Image *m_thumbnail;

		Animation *m_battleAnimation;

		bool m_equipped;
};

#endif // ITEM_HPP_
