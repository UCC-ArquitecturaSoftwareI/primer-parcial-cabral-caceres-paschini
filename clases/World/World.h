/**
 * @title       Clase World
 * @file        World.h
 * @version     1.0
 * @date        10/05/2020.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */

#ifndef RAYLIBTEMPLATE_WORLD_H
#define RAYLIBTEMPLATE_WORLD_H

#include "../Character/Character.h"
/**
 * @class World
 * @brief Contiene la informacion de World
 */

class World {
private:
    float Grav; /**Float value. Valor de la Gravedad*/
    float Fric; /**Float value. Valor de friccion*/
    Character *player; /**Puntero a player*/
public:
    /**
     * Constructor de World
     * @param player1
     */
    World(Character *player1);
    /**
     * Funcion que maneja la velocidad teniendo en cuenta la friccion en X
     */
    void Friction();
    /**
     * Funcion que maneja la altura teniendo en cuenta la gravedad
     */
    void Gravity();
};



#endif //RAYLIBTEMPLATE_WORLD_H
