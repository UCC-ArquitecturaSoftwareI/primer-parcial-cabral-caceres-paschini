//
// Created by Camila Cabral on 25/04/2020.
//

#ifndef RAYLIBTEMPLATE_MAP_H
#define RAYLIBTEMPLATE_MAP_H
#include <raylib.h>
#include <string>
#include "../../libs/tileson.hpp"

class Mapa {
private:
    tson::Map map;
    Texture2D map_tex;
    tson::Tileset *map_tileset;

public:
    Vector2 player_init_pos;

    Mapa(std::string file);


    void draw();
};

#endif //RAYLIBTEMPLATE_MAP_H
