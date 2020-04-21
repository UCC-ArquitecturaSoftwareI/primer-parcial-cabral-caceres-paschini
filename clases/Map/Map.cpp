//
// Created by Martin on 18/04/2020.
//

#include "Map.h"
#include <iostream>

Map::Map(std::string file) {
    tson::Tileson parser;
    map = parser.parse(fs::path(file));

    if (map.getStatus() == tson::ParseStatus::OK)
        for (auto &tileset :map.getTilesets()) {
            map_tileset = &tileset;
            map_text = LoadTexture(fs::path("../resources/level/" + tileset.getImage().string()).c_str());
        }
}

const tson::Map Map::getMap() const {
    return map;
}

const Texture2D &Map::getMapText() const {
    return map_text;
}

tson::Tileset *Map::getMapTileset() const {
    return map_tileset;
}
