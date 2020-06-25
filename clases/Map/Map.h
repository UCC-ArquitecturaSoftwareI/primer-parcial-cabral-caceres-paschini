/**
 * @title       Clase Map
 * @file        Map.h
 * @version     1.0
 * @date        18/04/2020.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */

#ifndef RAYLIBTEMPLATE_MAP_H
#define RAYLIBTEMPLATE_MAP_H

#include <string>
#include <raylib.h>
#include "../../Libs/tileson.hpp"
#include <vector>
#include <map>
/**
 * @class Map
 * @brief Contiene informacion del mapa y sus colisions
 */
class Map {
    tson::Map map; /**Map value. Contiene el mapa */
    std::vector<Texture2D> map_text; /**Vector value texture 2D. Contiene las texturas*/
    std::vector<tson::Tileset *> map_tileset;/**Vector value Tileset. Contiene tilesets*/
    std::string path;/**String value. Contiene el path a los recursos del mapa */
    std::vector<Rectangle> Colilision; /**Vector value rectangle. Contiene las posiciones de el piso y paredes*/
    std::vector<Rectangle> ColPlataform;/**Vector value rectangle. Contiene las posiciones de las plataformas*/
    std::vector<Rectangle> Trap;/**Vector value rectangle. Contiene las posiciones de las trampas*/
    std::vector<Vector2> Vec_fru;/**Vector value Vector2. Contiene las posiciones de las frutas*/
    std::multimap<std::string, Rectangle> Enemies;/**Multimap value string, rectanglue. Contiene las posiciones de los enemigos*/
public:
    /**
     * Constructor deL mapa
     * @param file
     */
    Map(std::string file);
    /**
     * Const value. Obtiene el mapa
     * @return map
     */
    const tson::Map &getMap() const;
    /**
     * Const value. Obtiene maptext
     * @return map_text
     */
    const std::vector<Texture2D> &getMapText() const;
    /**
     * Const value. Obtiene el maptileset
     * @return map_tileset
     */
    const std::vector<tson::Tileset *> &getMapTileset() const;
    /**
     * Vector value. Obtiene la posicion del character
     * @return Playerpos
     */
    Vector2 ReturnCharPos();
    /**
     * Vector value. Obtiene la posicion del piso y paredes
     * @return Colilision
     */
    std::vector<Rectangle> *Return_Floor();
    /**
     * Vector value. Obtiene la posicion de las plataformas
     * @return ColPlataform
     */
    std::vector<Rectangle> *Return_Plataform();
    /**
     * Vector value. Obtiene la posicion de las frutas
     * @return Vec_fru
     */
    std::vector<Vector2> *Get_Fruits();
    /**
     * Vector value. Obtiene la posicion de las trampas
     * @return Trap
     */
    std::vector<Rectangle> *ReturnTraps();
    /**
     * Multimap value. Obtiene la posicion de los enemigos
     * @return Enemies
     */
    std::multimap<std::string, Rectangle> *Get_enemies();

};


#endif //RAYLIBTEMPLATE_MAP_H
