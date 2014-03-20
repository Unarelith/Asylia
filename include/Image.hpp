/*
 * =====================================================================================
 *
 *       Filename:  Image.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/03/2014 22:10:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef IMAGE_HPP_
#define IMAGE_HPP_

class Image {
	public:
		Image(const char *filename);
		Image(SDL_Surface *surface);
		~Image();
		
		void render();
		void render(s16 x, s16 y, u16 w = 0, u16 h = 0, s16 clipX = -1, s16 clipY = -1, u16 clipW = 0, u16 clipH = 0);
		
		void setPosRect(s16 x, s16 y, u16 w, u16 h);
		void setClipRect(s16 x, s16 y, u16 w, u16 h);
		
		void setAlpha(u8 alpha) { SDL_SetTextureAlphaMod(m_texture, alpha); }
		
		u16 width() const { return m_width; }
		u16 height() const { return m_height; }
		
		SDL_Texture *texture() const { return m_texture; }
		
	protected:
		u16 m_width;
		u16 m_height;
		
		SDL_Surface *m_surface;
		SDL_Texture *m_texture;
		
		SDL_Rect m_clipRect;
		SDL_Rect m_posRect;
};

#endif // IMAGE_HPP_
