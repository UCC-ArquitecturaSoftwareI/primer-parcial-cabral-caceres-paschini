//
// Created by Camila Cabral on 25/04/2020.
//
#include <iostream>
#include "Map.h"
#include <cmath>
Mapa::Mapa(std::string file) {
    tson::Tileson parser;
    map=parser.parse(fs::path(file));
    if(map.getStatus()==tson::ParseStatus::OK)
    {
        for(auto &tileset : map.getTilesets()){
            map_tex=LoadTexture(fs::path("resources/Nivel3/" + tileset.getImagen().string()).c_str());
            map_tileset=&tileset;
        }
        auto objs=map.getLayer("Object");
        tson::Objet *player =objs->firtObj("player");
        player_init_pos.x=player->getPosition().x;
        player_init_pos.y=player->getPosition().y;
//Cuando personalizamos nuestro tiled podemos pedir que no de la infromacion de nuestro player ejemplo la velocidad.
      // std::cout<< "Velocidad: "<<player->get<int>("Velocidad")<<std::endl;
        //Agrega mas objetos
        for(auto &obj : objs->getObjects()){
            std::cout<<"Nombre"<<obj.getName()<<std::endl;
            std::cout<<"Pos: "<<obj.getPosition().x<<std::endl;
        }
    }
}
/*static void Up
void Mapa::draw() {
    DrawTexture(Map,0,0,YELLOW);
}*/

void Mapa::draw() { //esto es para el Tileset
    Rectangle tile_rec;
    tile_rec.x=0.0f; //va cortando cada figurita :D
    tile_rec.y=0.0f;
    tile_rec.width=map.getTileSize().x;
    tile_rec.height=map.getTileSize().y; //ver en el mapa de Tiled y poner de ahi la info que sale (VER)

    int firstId=map_tileset->getFirstgid();

    int columns=map_tileset->getColumns();

    int margin=map_tileset->getMargin();

    int space=map_tileset->getSpacing();


    auto &c=map.getBackgroundColor();


    ClearBackground({c.r,c.g,c.b,c.a});//limpiar la plantalla en blanco
//LEE EL FONDO DEL NIVEL 3
    for(auto nombre:{"fondo","Terreno"}){
        //ACORDATE QUE EN TILED PONER EN COLISION QUE ES CADA COSA !!
        auto  *layer=Mapa.getLayer(nombre);
        for(auto &[pos, tile] : layer->getTileData()){
            if(tile!= nullptr){

                tson::Vector2f position={(float) std::get<0>(pos) * map.getTileSize().x,
                                         (float) std::get<1>(pos) * map.getTileSize().y};
                int baseTilePosition=(tile->getId() - firstId);
                int tileModX=(baseTilePosition % columns);
                int currentRow=(baseTilePosition/columns);
                int offsetX=tileModX * (map.getTileSize().x + space) + margin;
                tile_rec.x=offsetX;
                tile_rec.y=offsetY;
                DrawTextureRec {map_tex,tile_rec,{position.x,position.y},WHITE};
            }
        }

    }

}

