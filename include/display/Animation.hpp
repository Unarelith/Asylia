/*
 * =====================================================================================
 *
 *       Filename:  Animation.hpp
 *
 *    Description:
 *
 *        Created:  24/05/2014 15:49:52
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ANIMATION_HPP_
#define ANIMATION_HPP_

class Battler;

class Animation : public Sprite {
	public:
		Animation(const char *filename, std::string name, u16 delay, std::vector<u16> frames, u16 frameWidth = 192, u16 frameHeight = 192);
		~Animation();

		void play(Battler *target);

		std::string name() const { return m_name; }

	private:
		std::string m_name;
};

#endif // ANIMATION_HPP_
