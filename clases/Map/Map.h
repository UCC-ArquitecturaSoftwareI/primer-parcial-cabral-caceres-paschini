//
// Created by Martin on 18/04/2020.
//

#ifndef RAYLIBTEMPLATE_MAP_H
#define RAYLIBTEMPLATE_MAP_H

#include <string>
#include <raylib.h>
#include "../../Libs/tileson.hpp"
#include <list>
#include <vector>

class Map {
    tson::Map map;
    std::vector<Texture2D> map_text;
    std::vector<tson::Tileset *> map_tileset;
    std::string path;
    std::list<Rectangle> Colilision;
    std::list<Rectangle> ColPlataform;
public:
    Map(std::string file);

    const tson::Map &getMap() const;

    const std::vector<Texture2D> &getMapText() const;

    const std::vector<tson::Tileset *> &getMapTileset() const;

    Vector2 ReturnCharPos();

    std::list<Rectangle> *ReturnList(int i);

};


#endif //RAYLIBTEMPLATE_MAP_H
