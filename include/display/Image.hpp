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
		Image();
		Image(const Image &img);
		Image(const char *filename);
		Image(SDL_Surface *surface);
		~Image();
		
		void reload(const char *filename);
		void reload(SDL_Surface *surface);
		
		void renderCopy();
		void render(s16 x = -1, s16 y = -1, u16 w = 0, u16 h = 0, s16 clipX = -1, s16 clipY = -1, s16 clipW = -1, s16 clipH = -1);
		
		void setPosRect(s16 x, s16 y, u16 w, u16 h);
		void setClipRect(s16 x, s16 y, u16 w, u16 h);
		
		void setAlphaMod(u8 alpha) { SDL_SetTextureAlphaMod(m_texture, alpha); }
		void setColorMod(Color color) { SDL_SetTextureColorMod(m_texture, color.r, color.g, color.b); setAlphaMod(color.a); }
		
		std::string filename() const { return m_filename; }
		
		u16 width() const { return m_width; }
		u16 height() const { return m_height; }
		
		SDL_Texture *texture() const { return m_texture; }
		
		SDL_Rect posRect() const { return m_posRect; }
		
		bool hidden() const { return m_hidden; }
		
		void hidden(bool hidden) { m_hidden = hidden; }
		
	protected:
		std::string m_filename;
		
		u16 m_width;
		u16 m_height;
		
		SDL_Texture *m_texture;
		
		SDL_Rect m_clipRect;
		SDL_Rect m_posRect;
		
		bool m_hidden;
};

#endif // IMAGE_HPP_
