//
// Created by Martin on 18/04/2020.
//

#include "Map.h"
#include <iostream>

Map::Map(std::string file) {
    tson::Tileson parser;
    map = parser.parse(fs::path(file.c_str()));

    if (map.getStatus() == tson::ParseStatus::OK)
        for (auto &tileset :map.getTilesets()) {
            std::cout << (fs::path("resources/level/" + tileset.getImage().string()).string()).c_str() << std::endl;
            std::string pepe = (fs::path("resources/level/" + tileset.getImage().string()).string());
            map_text = LoadTexture(pepe.c_str());
            map_tileset = &tileset;
        }


    tson::Layer *layer = map.getLayer("Floor_&_Wall");
    for (auto &obj : layer->getObjects()) {
        Rectangle Rec;
        Rec.x = obj.getPosition().x;
        Rec.y = obj.getPosition().y;
        Rec.width = obj.getSize().x;
        Rec.height = obj.getSize().y;

        Colilision.push_front(Rec);
    }
}


const Texture2D &Map::getMapText() const {
    return map_text;
}

tson::Tileset *Map::getMapTileset() const {
    return map_tileset;
}

Vector2 Map::ReturnCharPos() {
    tson::Layer *layer = map.getLayer("Player");
    tson::Object *player = layer->firstObj("Play");

    Vector2 Playerpos;
    Playerpos.x = player->getPosition().x;
    Playerpos.y = player->getPosition().y;
    return Playerpos;
}

const tson::Map &Map::getMap() const {
    return map;
}

std::list<Rectangle> *Map::ReturnList() {
    return &Colilision;
}

