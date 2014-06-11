/*
 * =====================================================================================
 *
 *       Filename:  Map.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/03/2014 22:40:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef MAP_HPP_
#define MAP_HPP_

class Map {
	public:
		Map(const char *filename, u16 x, u16 y, u16 area, u8 layers, u16 tilesetID);
		~Map();
		
		void addEvent(Event *event);
		Event *getEvent(std::string name);
		
		void eventsUpdate();
		
		void loadTile(u16 tileX, u16 tileY, u8 layer);
		void load();
		
		void render();
		void renderOverlay();
		
		s16 getTile(u16 tileX, u16 tileY, u16 layer);
		
		Tileset *tileset() const { return m_tileset; }
		
		u16 width() const { return m_width; }
		u16 height() const { return m_height; }
		
		u8 layers() const { return m_layers; }
		
		std::vector<Event*> events() const { return m_events; }
		
		static s32 scrollX;
		static s32 scrollY;
		
		static s32 getScrollX() { return scrollX; }
		static s32 getScrollY() { return scrollY; }
		
		static void centerMapWithObject(s16 x, s16 y, u16 w, u16 h);
		
	private:
		Tileset *m_tileset;
		
		u16 m_x;
		u16 m_y;
		
		u16 m_width;
		u16 m_height;
		
		u16 m_area;
		
		u8 m_layers;
		s16 **m_data;
		
		SDL_Texture *m_sublayersTex;
		SDL_Texture *m_overlayTex;
		Uint32 m_pixelFormat;
		
		std::vector<Event*> m_events;
		
		Image *m_battleback;
};

#endif // MAP_HPP_
