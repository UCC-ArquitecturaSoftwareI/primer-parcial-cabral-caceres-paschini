/**
 * @title       Clase Slime
 * @file        Slime.h
 * @version     1.0
 * @date        7/6/20.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */
#ifndef RAYLIBTEMPLATE_SLIME_H
#define RAYLIBTEMPLATE_SLIME_H

#include "../../Entity/Entity.h"

#include "../Enemies.h"
/**
 * @class Slime
 * @brief Funcion para darle movimientos al Slime enemigo
 */
class Slime : public Enemies {
private:

public:
    /**
     * Inicializa al Slime
     * @param file
     * @param playpos
     */
    Slime(std::string file, Vector2 playpos) : Enemies(std::move(file), playpos) {
        Proportion = {44, 30};
        maxCol = {9, 9};
        State_x = 1;
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


#endif //RAYLIBTEMPLATE_SLIME_H
