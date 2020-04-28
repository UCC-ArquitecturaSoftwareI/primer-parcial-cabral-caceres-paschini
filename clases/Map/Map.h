//
// Created by Martin on 18/04/2020.
//

#ifndef RAYLIBTEMPLATE_MAP_H
#define RAYLIBTEMPLATE_MAP_H

#include <string>
#include <raylib.h>
#include "../../Libs/tileson.hpp"

class Map {
    tson::Map map;
    Texture2D map_text;
    tson::Tileset *map_tileset;
public:
    Map(std::string file);

    tson::Map getMap();

    const Texture2D &getMapText() const;

    tson::Tileset *getMapTileset() const;

    Vector2 ReturnCharPos();

};


#endif //RAYLIBTEMPLATE_MAP_H
