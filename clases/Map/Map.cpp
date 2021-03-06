#include "Map.h"
#include <iostream>

Map::Map(std::string file) {
    tson::Tileson parser;
    map = parser.parse(fs::path(file.c_str()));

    if (map.getStatus() == tson::ParseStatus::OK)
        for (auto &tileset :map.getTilesets()) {
            std::cout << (fs::path("resources/level/" + tileset.getImage().string()).string()).c_str() << std::endl;
            std::string pepe = (fs::path("resources/level/" + tileset.getImage().string()).string());
            map_text.push_back(LoadTexture(pepe.c_str()));
            map_tileset.push_back(&tileset);
        }
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


const std::vector<Texture2D> &Map::getMapText() const {
    return map_text;
}

const std::vector<tson::Tileset *> &Map::getMapTileset() const {
    return map_tileset;
}

std::vector<Vector2> *Map::Get_Fruits() {
    tson::Layer *layer = map.getLayer("Fruits");
    for (auto &obj : layer->getObjects()) {
        Vector2 pos;
        pos.x = obj.getPosition().x;
        pos.y = obj.getPosition().y;
        Vec_fru.push_back(pos);
    }
    return &Vec_fru;
}

std::vector<Rectangle> *Map::ReturnTraps() {
    tson::Layer *layer = map.getLayer("Traps");
    for (auto &obj : layer->getObjects()) {
        Rectangle rec;
        rec.x = obj.getPosition().x;
        rec.y = obj.getPosition().y;
        rec.width = obj.getSize().x;
        rec.height = obj.getSize().y;
        Trap.push_back(rec);
    }
    return &Trap;
}

std::multimap<std::string, Rectangle> *Map::Get_enemies() {
    tson::Layer *layer = map.getLayer("Enemies");
    for (auto &obj : layer->getObjects()) {
        Rectangle rec;
        rec.x = obj.getPosition().x;
        rec.y = obj.getPosition().y;
        rec.width = obj.getSize().x;
        rec.height = obj.getSize().y;

        std::string temp = obj.getName();

        Enemies.emplace(temp, rec);
    }
    return &Enemies;
}



std::vector<Rectangle> *Map::Return_Plataform() {

    tson::Layer *layer2 = map.getLayer("Plataforms");
    for (auto &obj : layer2->getObjects()) {
        Rectangle Rec;
        Rec.x = obj.getPosition().x;
        Rec.y = obj.getPosition().y;
        Rec.width = obj.getSize().x;
        Rec.height = obj.getSize().y;
        ColPlataform.push_back(Rec);
    }

    return &ColPlataform;
}

std::vector<Rectangle> *Map::Return_Floor() {
    tson::Layer *layer = map.getLayer("Floor_&_Wall");
    for (auto &obj : layer->getObjects()) {
        Rectangle Rec;
        Rec.x = obj.getPosition().x;
        Rec.y = obj.getPosition().y;
        Rec.width = obj.getSize().x;
        Rec.height = obj.getSize().y;
        Colilision.push_back(Rec);
    }

    return &Colilision;
}





