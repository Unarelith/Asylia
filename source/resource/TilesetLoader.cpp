/*
 * =====================================================================================
 *
 *       Filename:  TilesetLoader.cpp
 *
 *    Description:
 *
 *        Created:  18/02/2019 08:38:33
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/resource/ResourceHandler.hpp>

#include "Tileset.hpp"
#include "TilesetLoader.hpp"

void TilesetLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	u16 id = 0;
	tinyxml2::XMLElement *tilesetElement = doc.FirstChildElement("tilesets").FirstChildElement("tileset").ToElement();
	while(tilesetElement) {
		std::stringstream tilesetFilename;
		std::stringstream tilesetInfoFilename;
		std::string name = tilesetElement->Attribute("name");

		tilesetFilename << "texture-tileset-" << name;
		tilesetInfoFilename << "resources/tilesets/" << name << ".tmx";

		Tileset &tileset = handler.add<Tileset>("tileset-" + std::to_string(id++));
		tileset.tiles.load(tilesetFilename.str());
		getNonPassableTiles(tilesetInfoFilename.str().c_str(), &tileset);

		tilesetElement = tilesetElement->NextSiblingElement("tileset");
	}
}

void TilesetLoader::getNonPassableTiles(const char *filename, Tileset *tileset) {
	gk::XMLFile doc(filename);

	tinyxml2::XMLElement *nonPassableTilesElement = doc.FirstChildElement("map").FirstChildElement("layer").NextSiblingElement().ToElement();
	if(!nonPassableTilesElement) return;

	u16 size = nonPassableTilesElement->IntAttribute("width") * nonPassableTilesElement->IntAttribute("height");

	tileset->nonPassableLayer = new u16[size];

	tinyxml2::XMLElement *tileElement = nonPassableTilesElement->FirstChildElement("data")->FirstChildElement("tile");

	for(u16 i = 0 ; i < size ; i++) {
		if(!tileElement) break;

		s16 tile = tileElement->IntAttribute("gid") - 1;

		if(tile == -1) tileset->nonPassableLayer[i] = 0;
		else tileset->nonPassableLayer[i] = tile;

		tileElement = tileElement->NextSiblingElement("tile");
	}
}

