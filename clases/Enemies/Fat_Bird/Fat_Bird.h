/**
 * @title       Clase Fat_Bird
 * @file        Fat_Bird.h
 * @version     1.0
 * @date        7/6/20.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */
#ifndef RAYLIBTEMPLATE_FAT_BIRD_H
#define RAYLIBTEMPLATE_FAT_BIRD_H

#include "../Enemies.h"
/**
 * @class Fat_Bird
 * @brief Funcion para los pollos enemigos
 */
class Fat_Bird : public Enemies {
private:

public:
    /**
     * Funcion para colocar la posicion del pollo
     * @param file
     * @param playpos
     */
    Fat_Bird(std::string file, Vector2 playpos) : Enemies(std::move(file), playpos) {
        Proportion = {40, 48};
        maxCol = {3, 3, 7};
        State_y =1;
    }
   /**
    * Funcion sin retorno
    */
    void move_x();
    /**
     * Funcion que añade los movimientos en el y, y usa la animacion para sus movimientos
     * Corre al enemigo si esta Colisionando
     */
    void move_y();

};


#endif //RAYLIBTEMPLATE_FAT_BIRD_H
