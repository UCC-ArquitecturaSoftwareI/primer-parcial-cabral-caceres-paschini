/**
 * @title       Clase Turtle
 * @file        Turtle.h
 * @version     1.0
 * @date        7/6/20.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */
#ifndef RAYLIBTEMPLATE_TURTLE_H
#define RAYLIBTEMPLATE_TURTLE_H

#include "../../Entity/Entity.h"

#include "../Enemies.h"
/**
 * @class Turtle
 * @brief Funcion para la tortuga del juego
 */
class Turtle : public Enemies {
private:

public:
    /**
     * Funcion que determina la posicion de la Turtle
     * @param file
     * @param playpos
     */
    Turtle(std::string file, Vector2 playpos) : Enemies(std::move(file), playpos) {
        Proportion = {44, 26};
        maxCol = {7, 7, 7, 7, 13, 13, 13, 13};
        State_x =1;

    }
    /**
     * Funcion que añade los movimientos en el x, y usa la animacion para sus movimientos
     */
    void move_x();
    /**
     * Funcion que no muestra nada
     */
    void move_y();

};


#endif //RAYLIBTEMPLATE_TURTLE_H
