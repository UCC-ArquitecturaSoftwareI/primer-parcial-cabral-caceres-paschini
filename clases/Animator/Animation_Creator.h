/**
 * @title       Clase Animation_Creator
 * @file        Animation_Creator.h
 * @version     1.0
 * @date        20/05/2020.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */

#ifndef RAYLIBTEMPLATE_ANIMATION_CREATOR_H
#define RAYLIBTEMPLATE_ANIMATION_CREATOR_H

#include <vector>
#include "../Fruits/Fruits.h"
#include "Image_Holder.h"
#include "unordered_map"
/**
 * @class Animation_Creator
 * @brief Toma cada imagen para armar el mapa
 */
class Animation_Creator {
    /**
     *Crea un mapa desordenado con un string de llave y guardo punteros de la clase image holder
     */
    std::unordered_map<std::string , Image_Holder*>  Map;
public:
    /**
     *Recibe un puntero de un vector de punteros de entidades y decide si debe crearle una imagen o usar una que ya estaba en uso
     * @param Vector_file
     */
    void Create(std::vector<Entity *> *Vector_file);
};


#endif //RAYLIBTEMPLATE_ANIMATION_CREATOR_H
