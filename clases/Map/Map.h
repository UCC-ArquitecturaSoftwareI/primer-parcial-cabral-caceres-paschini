//
// Created by Martin on 18/04/2020.
//

#ifndef RAYLIBTEMPLATE_MAP_H
#define RAYLIBTEMPLATE_MAP_H

#include <string>
#include <raylib.h>
#include "../../Libs/tileson.hpp"
#include <vector>
#include <map>

class Map {
    tson::Map map;
    std::vector<Texture2D> map_text;
    std::vector<tson::Tileset *> map_tileset;
    std::string path;
    std::vector<Rectangle> Colilision;
    std::vector<Rectangle> ColPlataform;
    std::vector<Rectangle> Trap;
    std::vector<Vector2> Vec_fru;
    std::multimap<std::string, Rectangle> Enemies;
public:
    Map(std::string file);

    const tson::Map &getMap() const;

    const std::vector<Texture2D> &getMapText() const;

    const std::vector<tson::Tileset *> &getMapTileset() const;

    Vector2 ReturnCharPos();

    std::vector<Rectangle> *Return_Floor();

    std::vector<Rectangle> *Return_Plataform();

    std::vector<Vector2> *Get_Fruits();

    std::vector<Rectangle> *ReturnTraps();

    std::multimap<std::string, Rectangle> *Get_enemies();

};


#endif //RAYLIBTEMPLATE_MAP_H
